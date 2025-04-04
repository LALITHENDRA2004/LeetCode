# Write your MySQL query statement below
SELECT B.product_name, A.year, A.price
FROM sales A
INNER JOIN 
product B
ON A.product_id = B.product_id;