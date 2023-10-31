CREATE TABLE CUSTOMERS(
    cust_id INT PRIMARY KEY,
    Name varchar(20) NOT NULL,
    Age INT NOT NULL,
    Address varchar(100) NOT NULL
);

INSERT INTO CUSTOMERS
VALUES
(1, "Ashik", 19, "Kerala"),
(2, "Jhonson", 29, "Kannur"),
(3, "Udayan", 20, "Alakode"),
(4, "Atxl", 23, "Kannur"),
(5, "Anu", 20, "Kannur");

SELECT * FROM CUSTOMERS;

SELECT UPPER(Name) FROM CUSTOMERS;

SELECT LOWER(Name) FROM CUSTOMERS;

SELECT cust_id, LTRIM(Name), Age, LTRIM(Address) FROM CUSTOMERS;

SELECT cust_id, RTRIM(Name), Age, RTRIM(Address) FROM CUSTOMERS;

SELECT CONCAT(Name, Address) FROM CUSTOMERS;

SELECT SUBSTRING(Name, 1, 3) FROM CUSTOMERS;

SELECT REPLACE("Ashik", "sh", "hs");

SELECT NOW();

SELECT ROUND(13.61);

SELECT POWER(2, 2);

SELECT MOD(8, 3);

SELECT SQRT(81);
