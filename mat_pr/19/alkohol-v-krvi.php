<html>
  <head>
    <title>PHP Test</title>
  </head>
  <body>
    <form>
    Mnozstvi alkoholu v dl
    <input name="d" type="text"> <br />
    Typ napoje: 
    <select name="e">
      <option value="12">vino</option>
      <option value="5">pivo 12</option>
      <option value="3.5">pivo 10</option>
      <option value="40">whisky</option>
    </select> <br />
    Hmotnost v kg 
    <input name="p" type="text"> <br />
    <input name="r" type="radio" value="0.68"> muz
    <input name="r" type="radio" value="0.55"> zena
    <br />

    <input type="submit" value="Submit">
    </form>
<?php 
if(isSet($_GET["d"]) && isSet($_GET["e"]) && isSet($_GET["p"]) && isSet($_GET["r"])) {
  echo ($_GET["d"] * $_GET["e"] * 0.8) / ($_GET["r"] * $_GET["p"]);
}
?>
  </body>
</html>