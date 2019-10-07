# Téma 4 - Příkazy pro řízení běhu programu
+ příkazy větvení - `if`, `switch`
	+ logické výrazy, relační operátory - `<`, `<=`, `==`, `>=`, `>` a logické spojky
+ podmíněný výraz
+ příkazy cyklu - `for`, `while`, `do while`
+ příkazy skoku - `continue`, `break`, ~~`goto`~~

pozn.:	`switch` - pokud `case x:` nemá příkaz skoku, provede se následující řádek.  
	V případě, že `number` je 1, následující program nám vypíše 1 i 2.
```cpp
switch(number)
{
case 1:
	std::cout << 1;
case 2:
	std::cout << 2;
	break;
}
```
