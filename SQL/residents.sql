--Get all emails
select email
from residents;

--Who was born in november
select * 
from residents
where extract(month FROM dob) = '11';

--Email sepcific rooms
select id as "Number", email 
from residents
where room NOT IN ('S302', 'S312');

--Born in november of 1994
select *
from residents
where extract(month from dob) = '11' and extract(year from dob) = '1994';

--find same birthdays
select * 
from residents
right join(
select dob 
from residents
group by dob
having count(*)>1
)A 
on A.dob = residents.dob;