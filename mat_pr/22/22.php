<html>
  <head>
    <title>PHP Test</title>
  </head>
  <body>
<?php
if($_GET["username"] == "Hugo" && $_GET["password"] == "Kokoshka") {
	echo "uspesne prihlaseni";
} else {
	echo "
    <form>
    Uzivatelske jmeno:
    <input name=\"username\" type=\"text\"> <br />

    Heslo:
    <input name=\"password\" type=\"password\"> <br />

    <input type=\"submit\" value=\"Submit\">
    </form>";
}
?>
  </body>
</html>
