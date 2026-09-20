select unique_id, name
from employees e
left join employeeuni m
on e.id = m.id;

