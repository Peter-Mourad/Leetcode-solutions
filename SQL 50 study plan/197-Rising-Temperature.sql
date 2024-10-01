select w1.id from Weather as w1
inner join weather as w2
where w1.recordDate = w2.recordDate + Interval 1 day
and w1.temperature > w2.temperature;