Select round(avg(order_date = customer_pref_delivery_date) * 100.0, 2) immediate_percentage
from delivery
where(customer_id, order_date) in
(
    select customer_id, min(order_date) from Delivery
    Group by customer_id
);