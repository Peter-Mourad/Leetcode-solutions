SELECT
    e.employee_id,
    COALESCE(ep.department_id, e.department_id) AS department_id
FROM Employee e
LEFT JOIN Employee ep 
ON e.employee_id = ep.employee_id AND ep.primary_flag = 'Y'
GROUP BY e.employee_id;