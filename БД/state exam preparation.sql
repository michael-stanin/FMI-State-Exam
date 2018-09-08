use movies;

/*------- July 2017 -------*/
------- Task 1 -------
SELECT studioname, title, year
FROM movie m
WHERE year = (SELECT max(year)
			  FROM movie
			  WHERE studioname = m.STUDIONAME);

SELECT name, SUM(MOVIE.LENGTH)
FROM movieexec JOIN movie ON producerc# = cert#
GROUP by name
HAVING MIN(year) < 1980;

SELECT starname, title, name, networth
FROM starsin JOIN movie ON movietitle=title AND movieyear=year
			 JOIN (SELECT cert#, networth, name
			       FROM movieexec
				   WHERE NETWORTH >= all(SELECT NETWORTH from MOVIEEXEC)) t
             ON t.CERT# = PRODUCERC#;

------- Task 2 -------
SELECT name, title, year
FROM movie JOIN MOVIEEXEC ON PRODUCERC# = CERT#
WHERE CERT# = ANY(SELECT PRODUCERC#
				  FROM movie
				  WHERE TITLE='Empire Strikes Back');

/* ------- July 2016 ------- */

------- Task 1 -------
SELECT t.NAME, title
FROM movie m join (
					SELECT name, cert#
					FROM MOVIEEXEC
					WHERE CERT# IN (SELECT PRODUCERC# FROM MOVIE WHERE title='Pretty Woman')
				) t
ON m.PRODUCERC# = t.CERT#;

------- Task 2 -------
SELECT studioname, starname, COUNT(*) as NumOfAppearances
FROM movie m JOIN starsin ON title=movietitle AND year=movieyear
WHERE studioname IS NOT NULL
GROUP BY studioname, starname
HAVING COUNT(*) >= ALL (SELECT COUNT(*)
						FROM movie, starsin
						WHERE title=movietitle
						AND year=movieyear
						AND studioname=m.studioname
						GROUP BY studioname, starname);

/* ------- September 2017 ------- */

------- Task 1 -------
/* заявката да изведе име и държава на корабите, които никога не са потъвали в битка (може и да не са участвали). */

use ships;

SELECT name
FROM SHIPS s JOIN OUTCOMES o ON class=ship
WHERE o.RESULT != 'sunk';

SELECT name, country
FROM SHIPS s JOIN OUTCOMES o ON name=ship
	         JOIN CLASSES c  ON s.CLASS=c.CLASS
WHERE o.RESULT != 'sunk' or result is NULL;

-- Real answer below --
SELECT name, country, result
FROM SHIPS LEFT JOIN OUTCOMES ON name=ship
                JOIN CLASSES ON SHIPS.CLASS=CLASSES.CLASS
WHERE result <> 'sunk' or result is NULL;

SELECT *
FROM SHIPS;

SELECT *
FROM OUTCOMES;


------- Task 2 -------

/* заявката да изведе име, водоизместимост и брой оръдия на най-леките кораби с най-много оръдия */

SELECT displacement, numguns
FROM CLASSES;

SELECT name, displacement, numguns
FROM CLASSES c JOIN SHIPS s ON c.CLASS=s.CLASS;

SELECT name, displacement, numguns
FROM CLASSES c JOIN SHIPS s ON c.CLASS=s.CLASS
WHERE displacement <= all( SELECT displacement FROM CLASSES ) AND
	  numguns >= all( SELECT numguns FROM CLASSES c1 WHERE c1.CLASS=c.CLASS);



-- Real answer below --
SELECT name, displacement, numguns
FROM CLASSES c JOIN SHIPS s ON c.CLASS=s.CLASS
WHERE displacement = ( SELECT min(displacement) FROM CLASSES ) AND
	  numguns = ( SELECT max(numguns) FROM CLASSES c1 WHERE c1.CLASS=c.CLASS);


------- Task 3 -------
/* заявката да изведе име на битките, в които е участвал един кораб */

SELECT *
FROM OUTCOMES
ORDER BY RESULT;

SELECT *
FROM BATTLES;

SELECT battle, name
FROM OUTCOMES o JOIN SHIPS s ON o.SHIP=s.name;

SELECT name, battle
FROM SHIPS s JOIN OUTCOMES o ON o.SHIP=s.name;

SELECT name, battle
FROM SHIPS s LEFT JOIN OUTCOMES o ON o.SHIP=s.name
ORDER BY BATTLE;



-- Real answer below?! most definately not!--
SELECT battle
FROM OUTCOMES o1
WHERE exists(SELECT *
			 FROM OUTCOMES o2 
			 WHERE o1.SHIP=o2.SHIP and o1.BATTLE <> o2.BATTLE);

			 
------- Task 4 -------
/* заявката, която извежда име на класа и брой на потъналите в битка кораби за съответния клас, за тези класове с повече от 5 кораба. */

/*  */


SELECT c.class, name
FROM CLASSES c JOIN SHIPS s ON c.CLASS=s.CLASS
ORDER BY CLASS;

-- Shows the ships count grouped by class
SELECT c.class, COUNT(name) as numberShips
FROM CLASSES c JOIN SHIPS s ON c.CLASS=s.CLASS
GROUP BY c.CLASS;

SELECT c.class
FROM CLASSES c JOIN SHIPS s ON c.CLASS=s.CLASS


SELECT c.class, name
FROM CLASSES c JOIN SHIPS s ON c.CLASS=s.CLASS
			   JOIN OUTCOMES o ON s.name=o.SHIP
;

-- Shows the class names of ships that have been sunk in battle.
SELECT c.class, name
FROM CLASSES c JOIN SHIPS s ON c.CLASS=s.CLASS
			   JOIN (SELECT ship
					 FROM OUTCOMES o
					 WHERE o.RESULT='sunk') o ON o.SHIP=s.NAME;

SELECT c.class, COUNT(name)
FROM CLASSES c JOIN SHIPS s ON c.CLASS=s.CLASS
			   JOIN (SELECT ship
					 FROM OUTCOMES o
					 WHERE o.RESULT='sunk') o ON o.SHIP=s.NAME
WHERE c.class IN (SELECT c.class
				  FROM CLASSES c JOIN ships s ON c.class=s.class
				  GROUP BY c.class
				  HAVING COUNT(name)>5)
GROUP BY c.class;

-- Real answer below --
SELECT class, COUNT(DISTINCT name)
FROM SHIPS s JOIN OUTCOMES o ON s.NAME=o.SHIP
WHERE result='sunk' AND class IN (SELECT c.class
								  FROM CLASSES c JOIN ships s ON c.class=s.class
								  GROUP BY c.class
								  HAVING COUNT(name)>5)
GROUP BY class;
