# Write your MySQL query statement below
select firstName,lastName,city,state from Person
LEFT join Address
ON Person.personId=Address.personId