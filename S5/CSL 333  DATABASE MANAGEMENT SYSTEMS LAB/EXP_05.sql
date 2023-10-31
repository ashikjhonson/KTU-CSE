CREATE TABLE MEMBER(
    Member_Id INT(11) PRIMARY KEY NOT NULL,
    Name VARCHAR(20) NOT NULL,
    Branch_Code INT(11) NOT NULL,
    Roll_No INT(11) NOT NULL,
    Email_Id VARCHAR(20),
    Date_Of_Join VARCHAR(20) NOT NULL,
    Phone_No INT(11) NOT NULL,
    Status VARCHAR(20) NOT NULL
);

INSERT INTO MEMBER (Member_id, Name, Branch_Code, Roll_No, Email_Id, Date_Of_Join, Phone_No, Status)
VALUES
(200, 'Ashik', 12345, 7731, 'ashik@gmail.com', '2023-09-20', 1234233, 'Single NRTM'),
(205, 'Jhonson', 12344, 7730, 'jhonson@gmail.com', '2022-09-20', 12441234, 'Solo RTM'),
(210, 'Anu', 12344, 7475, 'anu@gmail.com', '2023-06-13', 12352387, 'RTM'),
(215, 'Joy', 666, 6666, 'atxulj0y@gmail.com', '2023-09-15', 1274328, 'TM'),
(220, 'Xavi', 128734, 234, 'xavi@yahoo.com', '1903-09-20', 36547349, 'Single');

SELECT * FROM MEMBER;

DELETE FROM MEMBER
WHERE Member_Id=205;

DELETE FROM MEMBER
WHERE Member_Id=210;

UPDATE MEMBER
SET Status="Inactive"
WHERE Member_Id=200;

UPDATE MEMBER SET Status="Inactive" WHERE Member_Id=215;

UPDATE MEMBER SET Status="Inactive" WHERE Member_Id=220;

DELETE FROM MEMBER WHERE Status="Inactive";

SELECT * FROM MEMBER;
