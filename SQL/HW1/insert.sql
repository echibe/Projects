--Elliot Chibe

--I didn't have time to insert each column so I put elipses (...)


INSERT INTO RecCenterMember (id,f_name,l_name,DOB,family_id) VALUES(1,Abby,Smith,5/21/1983,1),
(2,Mike,O'Shea,7/4/1968, 2);
--...

INSERT INTO Class (id,title,type,instructor,season, year) 
VALUES(1,Needle points,Craft,3,Spring,2010), (2,Photography,Art,1,Fall,2008);

--...

INSERT INTO Instructor (id,f_name,l_name,member_id) 
VALUES(1,Annie,Heard,NULL), (2,Monica,Knapp,18);

--...

INSERT INTO Class (type,description) 
VALUES(Craft,'Knitting, sewing, ect'), (Art, 'Painting, sculpting, ect');
--...

INSERT INTO FamilyPackage (id,address, phone) 
VALUES(1,23 'Beacon St. Hillside IL'), (2, '4930 Dickens Ave Chicago IL');
--...

INSERT INTO Enrollment (class_id,member_id, cost) 
VALUES(3, 3, 20), (1, 9, 15);
--...