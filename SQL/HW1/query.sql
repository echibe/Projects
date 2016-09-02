--Elliot Chibe

--2
SELECT phone FROM FamilyPackage 
WHERE id IS (SELECT family_id from RecCenterMember
WHERE l_name == 'O'Shea'');


--3
SELECT Instructor.l_name, Instructor.id, Class.Title FROM Instructor, Class
JOIN Class
ON Instructor.id == Class.Instructor;

--4
SELECT f_name, l_name FROM RecCenterMember
WHERE family_id IS NULL;

--5
SELECT f_name, l_name from RecCenterMember
WHERE RecCenterMember.id == (SELECT member_id FROM Enrollment
WHERE class_id == {1,2,3,7,8});

--6


--7 
SELECT f_name, l_name from Instructor
WHERE Instructor.id == (SELECT instructor from Class
WHERE year=='2009' AND season==("Spring" OR "Fall"));
JOIN
SELECT description from Class_type
WHERE Class_type.type == (SELECT type FROM Class
WHERE year=='2009' AND season==("Spring" OR "Fall");

--8
SELECT Class.type, Class_typer.description FROM Class, Class_type
WHERE Class.year == ("2008" OR "2009") AND Class.type == Class_type.type  




