CREATE DATABASE vinoteka;
use vinoteka;

CREATE TABLE vino (
	id INT,
	barva VARCHAR(30),
	odruda VARCHAR(30),
	mnozstvi INT
);

INSERT INTO vino VALUES ( 0, "cervena", "nevim", 2 ), ( 1, "zelena", "neznam", 4 ), ( 2, "bila", "zadna", 8 );

CREATE TABLE dodavka (
	id INT,
	odruda VARCHAR(30),
	mnozstvi INT
);

INSERT INTO dodavka VALUES ( 3, "idk", 5 ), ( 2, "zadna", 9999 ), ( 1, "nevim", 8 );

SELECT * FROM vino;

UPDATE dodavka, vino SET vino.mnozstvi = vino.mnozstvi + dodavka.mnozstvi WHERE vino.odruda = dodavka.odruda;

SELECT * FROM vino;

DROP DATABASE vinoteka;
