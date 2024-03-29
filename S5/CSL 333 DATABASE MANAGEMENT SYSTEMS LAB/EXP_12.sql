CREATE TABLE SALES(
    Salesman_id INT PRIMARY KEY,
    Name VARCHAR(50),
    City VARCHAR(50),
    Commision INT
);

INSERT INTO SALES
VALUES
(1, "Ashik Jhonson", "Kannur", 10),
(2, "Hulk", "New York", 20),
(3, "Stark", "New York", 40);

CREATE VIEW SALES_NEWYORK AS
SELECT * FROM SALES
WHERE City LIKE "New York";

SELECT * FROM SALES_NEWYORK;

CREATE VIEW SALESPERSONS AS
SELECT Salesman_id, Name, City FROM SALES;

SELECT * FROM SALESPERSONS;

CREATE VIEW COUNT_CITY AS
SELECT City, COUNT(*) FROM SALES GROUP BY City;

SELECT * FROM COUNT_CITY;

DELETE FROM SALESPERSONS
WHERE Name='Ashik Jhonson';

SELECT * FROM SALESPERSONS;

DROP VIEW SALESPERSONS;

DROP VIEW SALES_NEWYORK;

SELECT * FROM SALES;
