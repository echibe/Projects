--Elliot Chibe

CREATE TABLE RecCenterMember
(
  id int PRIMARY KEY,
  f_name varchar(64),
  l_name varchar(64),
  dob date,
  family_id int
);

CREATE TABLE Class
(
  id int PRIMARY KEY,
  title varchar(64),
  season varchar(64),
  c_year int,
  c_type varchar(64) references Type(type),
  instructor varchar(64) references Instructor(id),
);

CREATE TABLE Instructor
(
  id int PRIMARY KEY,
  f_name varchar(64),
  l_name varchar(64),
  member_id int references RecCenterMember(id),
);

CREATE TABLE Type
(
  type varchar(64) PRIMARY KEY,
  description varchar(64),
);

CREATE TABLE FamilyPackage
(
  id int PRIMARY KEY,
  address varchar(64),
  phone int,
);

CREATE TABLE Enrollment
(
  class_id int references Class(id) PRIMARY KEY,
  member_id int references RecCenterMember(id) KEY,
  cost int,
  c_type varchar(64) references Type(type),
  instructor varchar(64) references Instructor(id),
);
