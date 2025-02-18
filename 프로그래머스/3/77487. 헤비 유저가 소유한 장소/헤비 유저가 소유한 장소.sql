SELECT * 
FROM PLACES
WHERE HOST_ID IN (SELECT HEAVY_ID 
                  FROM 
                  (SELECT  HOST_ID HEAVY_ID, COUNT(HOST_ID) HOST_COUNT
                    FROM PLACES
                    GROUP BY HOST_ID
                    HAVING HOST_COUNT > 1) SUB)      
ORDER BY ID