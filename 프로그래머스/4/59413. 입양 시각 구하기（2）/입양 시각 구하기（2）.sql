SET @C = -1;
SELECT a.HOUR, IFNULL(b.COUNT, 0) AS COUNT
FROM (SELECT @C:=@C+1 AS HOUR
    FROM ANIMAL_OUTS WHERE @C < 23) AS a
LEFT JOIN (SELECT HOUR(DATETIME) AS HOUR, 
           COUNT(*) AS COUNT
           FROM ANIMAL_OUTS GROUP BY 1) b
ON b.HOUR = a.HOUR  
ORDER BY 1




# SET @C = -1;
# SELECT *
# FROM ( SELECT @C:=@C+1 AS HOUR1
#          FROM ANIMAL_OUTS WHERE @C < 24 ) AS sub2,
#          (SELECT HOUR(DATETIME) AS HOUR, COUNT(*) AS COUNT FROM ANIMAL_OUTS GROUP BY HOUR ) AS sub
#          ORDER BY HOUR;


# SELECT HOUR(DATETIME) AS HOUR, COUNT(*) AS COUNT FROM ANIMAL_OUTS GROUP BY 1 ORDER BY 1
#  SET @C = -1;
# SELECT @C:=@C+1 AS HOUR
#          FROM ANIMAL_OUTS WHERE @C < 24 