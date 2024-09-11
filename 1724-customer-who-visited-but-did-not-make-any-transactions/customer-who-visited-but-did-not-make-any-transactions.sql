# Write your MySQL query statement below
Select  customer_id ,count(customer_id) as count_no_trans from Visits where visit_id NOT IN(SELECT visit_id from Transactions) GROUP by customer_id