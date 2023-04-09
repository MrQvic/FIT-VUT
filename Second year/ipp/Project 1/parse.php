<?php
/*  parse.php
    autor:xmrkva04 */
ini_set("display_errors", "stderr");

function help()
{   
    echo("Skript prování lexikální a synstaktickou analýzu jazyka IPPcode23 a následně generuje XML kód.");
    echo("\n");
    echo("Spuštění: php parser.php <file.IPPcode23");
    echo("\n");
}

/*  Funkce uncomment odstraňující komentáře a přebytečné mezery na řádku */
function uncomment($line)
{
    $line = preg_replace("/#.*/","",$line);
    $line = preg_replace(array('/\s{2,}/', '/[\t\n]/'), ' ', $line);
    return $line;
}

/*  Pomocná funkce pro generaci XML - rozhoduje o typu proměnné a její hodnotě*/
function type_content($split)
{
    $tmp = explode("@", $split);
    $type = $tmp[0];
    if($type == "GF" or $type == "LF" or $type == "TF")
    {
        $type = "var";
        $content = $split;
    }
    elseif($type != "string" and $type != "int" and $type != "bool" and $type != "nil" )
    {
        $type = "label";
        $content = $tmp[0];
    }
    else
        if($type == "string")
            $content = substr($split,7);
        else
            $content = $tmp[1];

    return array($type,$content);
}

/*  Generace XML kódu */
function xml_gen($args,$order,$opcode,$line)
{
    $line = str_replace("&","&amp;",$line);
    $line = str_replace("<","&lt;",$line);
    $line = str_replace(">","&gt;",$line);
    $split = explode(" ", $line);
    echo("\t".'<instruction order="'.$order.'" opcode="'.$opcode.'">'."\n");
    if($args != 0)
    {
        for ($i = 1; $i <= $args; $i++)
        {   
            $vars = type_content($split[$i]);
            if($opcode == "READ" and $i == 2)
            {
                echo("\t\t".'<arg'.$i.' type="type">'.$vars[0].'</arg'.$i.'>');
                echo("\n");
            }
            else
            {
                echo("\t\t".'<arg'.$i.' type="'.$vars[0].'">'.$vars[1].'</arg'.$i.'>');
                echo("\n");
            }
        }
    }
    echo("\t".'</instruction>'."\n");
    global $order;
    $order = $order + 1;
}


/*  Funkce zajišťující syntaktickou správnost kódu pomocí regexů */
function type_ok($text)
{
    return preg_match("/^(int|string|bool)$/", $text);
}

function int_ok($text)
{
    return  preg_match("/^int@(?:0|[1-9][0-9]*)$/", $text)  || 
            preg_match("/^int@(\-|\+)?[0-9][0-9]*$/",$text) ||
            preg_match("/^int@0x([0-9A-F]*)$/", $text)      ||
            preg_match("/^int@0[0-8]*$/", $text);
}

function bool_ok($text)
{
    return preg_match("/^bool@(true|false)$/", $text);
}

function nil_ok($text)
{
    return preg_match("/^nil@nil$/", $text);
}

function string_ok($text)
{
    return preg_match("/^string@([^\\\]|\\\[0-9][0-9][0-9])*$/", $text);
}

function symb_ok($text)
{
    return  int_ok($text) ||    //int check
            bool_ok($text)||    //bool check
            nil_ok($text) ||    //nil check
            string_ok($text);   //string check
}

function var_ok($text)
{
    return preg_match('/^(GF|TF|LF)@[a-zA-Z_$-&%!*?][a-zA-Z_$-&%!*?0-9]*$/', $text);
}

function label_ok($text){
    return preg_match("/^[a-zA-Z_\-$&%*!?][a-zA-Z0-9_\-$&%*!?]*$/", $text);
}

/*************************MAIN*****************************/
$file = fopen('php://stdin', 'r') or die (11);

if ($argc == 2 and ($argv[1] == "--help")) 
{
    help();
    exit(0);
} 
else if ($argc > 1)
    exit(10);

$header = false;
$order = 1;

while($line = fgets($file))
{   
    $line = uncomment($line);
    $line = trim($line);

    if($line == "")
        continue;

    $headline = strtoupper($line);

    if($header == false and $headline == ".IPPCODE23")
    {   
        $header = true;
        echo('<?xml version="1.0" encoding="UTF-8"?>');
        echo("\n");
        echo('<program language="IPPcode23">');
        echo("\n");
        continue;
    }
    elseif ($header == false and $line != ".IPPcode23")
    {
        exit(21);
    }

    $split = explode(" ", $line);
    $args = count($split) - 1;
    if($split[0] == "")
        continue;
    $opcode = strtoupper($split[0]);
    switch($opcode)
    {   
        //0 args:
        case "CREATEFRAME":
        case "PUSHFRAME":
        case "POPFRAME":
        case "RETURN":
        case "BREAK":
            if ($args != 0)
                exit(23);
            xml_gen(0,$order, $opcode, $line);
            break;
        
        //1 arg   :var
        case "DEFVAR":
        case "POPS":
            if ($args != 1)
                exit(23);

            if(!var_ok($split[1]))
                exit(23);

            xml_gen(1,$order, $opcode, $line);
            break;
        //          :label
        case "CALL":
        case "LABEL":
        case "JUMP":
            if ($args != 1)
                exit(23);

            if(!label_ok($split[1]))
                exit(23);

            xml_gen(1,$order, $opcode, $line);
            break;

        //          :symb
        case "PUSHS":
        case "WRITE":
        case "EXIT":
        case "DPRINT":

            if ($args != 1)
                exit(23);

            if(!symb_ok($split[1]) and !var_ok($split[1]))
                exit(23);

            xml_gen(1,$order, $opcode, $line);
            break;

        //2 args: var,symb
        case "MOVE":
        case "INT2CHAR":
        case "NOT":
        case "STRLEN":
        case "TYPE":
            if ($args != 2)
                exit(23);

            if (!var_ok($split[1]) or !(symb_ok($split[2]) or var_ok($split[2])))
                exit(23);
                
            xml_gen(2,$order, $opcode, $line);
            break;
        
        case "READ":
            if ($args != 2)
                exit(23);

            if (!var_ok($split[1]) or !type_ok($split[2]))
                exit(23);

            xml_gen(2,$order, $opcode, $line);
            break;
        
        //3 arg:    var,symb,symb
        case "ADD":
        case "SUB":
        case "MUL":
        case "IDIV":
        case "LT":
        case "GT":
        case "EQ":
        case "AND":
        case "OR":
        case "STRI2INT":
        case "CONCAT":
        case "GETCHAR":
        case "SETCHAR":

            if ($args != 3)
                exit(23);

            if(!var_ok($split[1]) or !(symb_ok($split[2]) or var_ok($split[2])) or !(symb_ok($split[3]) or var_ok($split[3])))
                exit(23);

            xml_gen(3,$order, $opcode, $line);
            break;

        //          label,symb,symb
        case "JUMPIFEQ":
        case "JUMPIFNEQ":
            if ($args != 3)
                exit(23);

            if(!label_ok($split[1]) or !(symb_ok($split[2]) or var_ok($split[2])) or !(symb_ok($split[3]) or var_ok($split[3])))
                exit(23);

            xml_gen(3,$order, $opcode, $line);
            break;

        default:
            exit(22);
    }
}
echo('</program>'."\n");
exit(0);
?>