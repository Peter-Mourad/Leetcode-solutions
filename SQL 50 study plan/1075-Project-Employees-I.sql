select P.project_id, round(Avg(E.experience_years), 2) average_years 
From Project P
Inner join Employee E 
ON P.employee_id = E.employee_id
Group by P.project_id;