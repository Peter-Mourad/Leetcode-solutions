# Write your MySQL query statement below
SELECT p.product_id 
FROM Products p
WHERE   p.recyclable = 'Y' 
        and p.low_fats = 'Y' 