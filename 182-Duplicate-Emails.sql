select Email from Person
Group by Email
Having Count(Email) > 1;
