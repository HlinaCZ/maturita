
## Základní pojmy

### Informatika

* obor zabývající se zpracováním informací

#### Základní pojmy

* **Byte**

  * jednotka množství dat
  * značíme **B**, **1 Byte = 8 bitů**
  * 1kB = 2^10B, 1MB = 2^20B, 1GB = 2^30B, 1TB = 2^40B

  * **Bit**

    * dvojková číslice - základní jednotka množství dat
    * značíme **b** - nabývá hodnot **0**, **1** 

* **Informace**

  * data vypovídající zprávu o dané věci

  * **Data**
    * údaje, hodnoty, čísla, znaky, symboly, ...

* **Algoritmus**

  * jednoznačný postup pro řešení problému s požadovaným výsledkem
  * vlastnosti:
    * **hromadnost** - je určen pro řešení větší skupiny úloh stejného typu
    * **podmíněnost** - každý příkaz je podmíněn předchozími příkazy a podmiňuje následující příkazy
    * **konečnost** - algoritmus po určitém počtu příkazů skončí

* **Program**

  * algoritmus zapsaný v programovacím jazyce, řeší konkrétní problém
  * **posloupnost instrukcí**
  * může být **interpretovaný** / **vykonávám procesorem** (po přeložení do zdrojového kódu)

  * **Instrukce**
  
    * příkaz pro provedení (jednoduché) činnosti/operace technickým vybavením počítače (procesorem)

* **Interpret**
* program, který vykonává jiný program ve zdrojovém kódu
  
* **Překladač** (Kompilátor)
* program, který překládá **zdrojový kód** do **strojového kódu** pro cílový procesor

##### von Neumannovo schéma

* složení:
  * **paměť**
    * zařízení pro uchování informací (binárně kódovaných dat)
    * **kapacita** paměti = množství informací, které je možné do paměti uložit
    * dělí se na buňky a je označena číslem = **adresa paměti**

      * **Vnitřní (operační) paměť** - slouží k uchování momentálně zpracovaných dat a programů
      * **Vnější (periferní) paměť** - slouží k dlouhodobému ukládání dat 
      
      * **ROM** - Read-only memory = paměť určená pouze ke čtení
      * **RAM** - Random-access memory = paměť s **přímým přístupem**

      * Paměť s **přímým** přístupem = můžeme ihned přistoupit na požadovanou adresu
      * Paměť se **sekvenčním** přístupem = pro přístup musíme přečíst nejprve všechna předcházející místa (0..n-1)

  * **ALU** = aritmetiko-logická jednotka (sčítání, násobení, porovnávání)
  * **řadič**
    * řídící jednotka
    * řídí pomocí **řídících signálů**, které jsou k jendnotlivým modulům zasílány
    * k řadiči jsou zasílány **stavové hlášení** od jednotlivých modulů

  * **vstupní/výstupní zařízení**
    * vstupní zařízení = vstup programu a dat
    * výstupní = výstup -||-

* Pravidla:
  1. počítač se skládá: viz složení
  2. Struktura počítače je nezávislá na řešeném problému
  3. V paměti jsou data uložená společně s instrukcemi programu
  4. Paměť rozdělena na buňky stejné velikosti
  5. Program je tvořen posloupnosti instrukcí
  6. Pořadí provádění instrukcí je sekvenční
  7. Instrukce, data a adresy jsou kódovány binárně

* **Procesor** = řadič + ALU
* **CPU** = procesor + operační paměť

* POstup činnosti:
  1. Do operační paměti se z vstupního zařízení pomocí ALU umístí program.
  2. Stejným způsobem se do oper. paměti umístí data.
  3. Proběhne výpočet zapomocí ALU, která provádí **instrukční cyklus**
    * načte instrukci &rarr; dekóduje instrukci &rarr; provede &rarr; výsledek uloží


#### Počítač

* zařízení, které zpracovává data pomocí programu

* **Firmware**

  * **mikroprogramové vybavení** (software), které slouží pro řízení vestavěných systémů
  * většinou není uživatelem modifikován

  * **BIOS**
    * **Basic Input Output System**
    * implementuje základní vstupní-výstupní funkce pro počítače
    * slouží hlavně pro inicializaci a konfiguraci hardwarových zařízení a spuštění operačního systému
    * uložen ve stálé (nevolatilní) paměti - ROM, EEPROM, flash

* **Hardware**

  * **Základní deska**
    * propojuje jednotlivé komponenty počítače

    * **(Mikro)procesor - CPU**
      * vykonává strojový kód (instrukce)
        
        * **Registr** - velmi rychlé místo malé pamětové kapacity
        * **Cache paměť** - slouží k uchovávání dat a následnému přístupu, také jako zásobník dat mezi různě rychlými komponenty

    * **Operační / vnitřní / hlavní paměť**
      * RWM, dnes se používá RAM
      * slouží k dočasnému uložení zpracovávaných dat a spuštěných programů

    * **Sběrnice** (bus)
      * propojuje vstupně-výstupní zařízení s procesorem
      * umožňuje připojení rozšiřujících karet (grafická, zvuková, síťová, ...)


  * **Pevný disk**
    * uchovává programy a data i po vypnutí počítače 
    * HDD (hard disk drive) - 
    * SSD (solid-state drive) - ,,polovodičový disk", 


  * **Elektrický zdroj**
    * slouží k napájení počítače a jeho komponent


  * **Periferie**
    * zařízení, které se připojuje k počítači a rozšiřuje jeho vlastnosti, (V/V zařízení)

* **Software**
  * **programové vybavení** - souhrný název pro veškeré programy
  * autorské dílo &rarr; licence

    * **Systémový software**
      * **Operační systémy** 
      * **Programy pro správu systému** (utility)

    * **Aplikační software**
      * Textové editory
      * Grafické editory
      * Tabulkové editory (procesory)
      * Databázové systémy
      * CAD (computer-aided design) programy
      * DTP (Desktop publishing) programy

    * Licence?
      * Shareware - program je chráněný autorským právem, po zkušební době je potřeba zaplatit
      * Freeware - program nemůže být upraven, autor má autorská práva, omezuje použití
      * Open Source <3 - kód software je volně dostupný k prohlížení, popř. úpravy a sdílení 



## Počítačové sítě

standard =
protokol = 

adresa = identifikuje zařízení připojedé do sítě
adresace 
  * MAC adresa = na 2. nejnižší vrstvě, identifikace v místní síti = LAN
    * adresa na síťové kartě, neměla by se dát změnit
    * 12 čísel rozdělené dvojtečkou po dvou
  * IP adresa
    * IPV4 = čtyři čísla oddělené tečkou, čísla od 0-255, 192.168.2.1
    * IPV6 = osm čtveřic čísel, v 16-kovém zápisu, 2001:db8::8a2e:370:7334
    * musí být specifická pro každé zařízení v celosvětové síti
    * NAT - v routeru nebo sít kartě, překládá mac adresu v místní síti do IP adresy

DNS = správce doménových jmen
  * autorita, která spravuje domény - má pravo přiřadit doménu nejvýššího řádu
  * cz.nic

Propojení síťi
  * Drátové
  * Bezdrátové

### Bezdrátová síť
  * síť, která umožujě účastníkům komunikovat bez kabeláže
  * přenos pomocí signálu mega
  * 802.11 kmitočet
  * typy
    * WPAN = wireless personal ? network
      * nejnižší, na nejkratší vzdálenost, bluetooth, nejčastěji 2 zařízeni
    * WLAN = wireless local area network
      * místní síť, v domácnostech
      * propojení 2 a více účastníků k síti
      * používáme modem = zařízení které mění anologový signál na digitální
        * součástí každého počítače
      * = přístupový bod, pro připojení k internetu

    * Wireless metropolitan area network
      * propojení více lokalních sítí
      * například pro celé město, nákupní cetrum
      * více modemů, které synchronizují signál
    * WWA
      * používá se celosvětově = 1G - 5G 
      * GMS = globální systém pro mobilní komunikaci
      * využívaný téměř celosvětově

#### aktivní prvek sítě
router = přijímá signál z vysílače --> vede signál do modemu
  * směřovač
gateway
  * počítač kam se přívádí do nějaké sítě internetový signál

repeater (opakovač)
  * zesiluje a 

hub
  * umožní připnout se k počítačům

switch
  * inteligentnější než hub = rozliší, který signál má jít ke kterému počítači

brigde
  * propujuje nějaké části sítě


4 vrstvý model
  * linková vrstva
    * nejnižší  

  * sítová vrstva
    * stará se o adresaci
  * transportní vrstva
    * kontroluje data, jtesli nej

  * aplikační vrstva
    * zajisťuje přenos konkrétní    

uživatelksá prává s síti
admin
  * veškerá práva
vedlejší admin
  * nemá veškerá práva, jsou specifikovaná

uživatelé
  * můžeme rozdělit do už. skupin
  * nejnižší práva