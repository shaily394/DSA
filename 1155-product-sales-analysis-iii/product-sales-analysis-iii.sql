# Write your MySQL query statement below
#when we use GROUP BY, every column in the SELECT clause must either:
#Be part of the GROUP BY, or
#Be wrapped inside an aggregate function (MIN(), MAX(), SUM(), etc).

select  product_id, year as first_year, quantity, price
from Sales where (product_id , year )     
in(
select  product_id, min(year) as first_year
from Sales
group by product_id);