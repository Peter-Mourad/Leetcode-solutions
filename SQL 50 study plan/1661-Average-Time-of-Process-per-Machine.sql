select a1. machine_id as machine_id, round(avg(a1.timestamp) - avg(a2.timestamp), 3) as processing_time from Activity as a1
inner join Activity as a2
On a1.machine_id = a2.machine_id
where a1.activity_type = "end" AND a2.activity_type = "start"
group by a1.machine_id;
