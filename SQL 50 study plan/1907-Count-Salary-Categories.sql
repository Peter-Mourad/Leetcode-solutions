SELECT "Low Salary" category, COUNT(if(income < 20000, 1, NULL)) accounts_count
FROM Accounts
UNION ALL
SELECT "Average Salary", COUNT(if(income >= 20000 AND income <= 50000, 1, NULL))
FROM Accounts
UNION ALL
SELECT "High Salary", COUNT(if(income > 50000, 1, NULL))
FROM Accounts;