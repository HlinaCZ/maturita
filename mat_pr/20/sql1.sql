CREATE DATABASE test;
use test;

CREATE TABLE knihy (
	nazev VARCHAR(30),
	autor VARCHAR(30),
	signatura VARCHAR (30)
);

INSERT INTO knihy VALUES ( "krtecek", "Miler", "m" ), ( "babicka", "Nemcova", "n" );

CREATE TABLE ctenari (
	jmeno VARCHAR(30),
	adresa VARCHAR(30),
	cislolegitimace INT
);

INSERT INTO ctenari VALUES ( "karel", "praha", 123 ), ( "pepa", "znojmo", 111 );

CREATE TABLE vypujcky (
	signatura VARCHAR(30),
	cislolegitimace INT,
	datumvypujcky DATE
);

INSERT INTO vypujcky VALUES ( "m", 123, "1000-01-01" ), ("n", 123, "2020-05-05" );

SHOW TABLES;
SELECT * FROM knihy;
SELECT * FROM ctenari;
SELECT * FROM vypujcky;

SELECT ctenari.jmeno, ctenari.adresa, ctenari.cislolegitimace, knihy.nazev, knihy.autor
FROM knihy, ctenari, vypujcky
WHERE DATEDIFF(CURRENT_DATE(), vypujcky.datumvypujcky) > 30
AND vypujcky.signatura = knihy.signatura
AND vypujcky.cislolegitimace = ctenari.cislolegitimace;

DROP DATABASE test;
