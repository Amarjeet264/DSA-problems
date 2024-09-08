# Write your MySQL query statement below
SELECT unique_id,name FROM EmployeeUNI as t1 RIGHT JOIN Employees as t2 ON t1.id = t2.id;