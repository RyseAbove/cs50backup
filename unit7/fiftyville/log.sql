-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Wanted background on crime

-- Took place on July 28, 2020 on Chamberlin Street
-- 10:15 a.m. inside the courthouse.
-- Three witnesses with interview transcripts that mention the courthouse.
SELECT * FROM crime_scene_reports
WHERE street = 'Chamberlin Street';

-- Read interview transcripts

-- Ruth - 10 minutes after the theft, saw the thief get into a car in the parking lot and leave. Look at security footage of the courthouse at that time
-- Eugene - Recognized the thief from that morning where the thief was withdrawing money from the ATM on Fifer Street
-- Raymond - Thief called someone before they left the courthouse, for about a minute. Thief was planning to leave ASAP on a flight. Person on other end of phone purchased ticket
SELECT * FROM interviews
WHERE year = 2020 AND month = 7 AND day = 28;

-- View courthouse security logs to find liscence plate #'s

-- 5P2BI95
-- 94KL13X
-- 6P58WS2
-- 4328GD8
-- G412CB7
-- L93JTIZ
-- 322W7JE
-- 0NTHK55
SELECT * FROM courthouse_security_logs
WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25 AND activity = 'exit';

-- Read transactions to find thief

-- 686048 - Ernest - (367) 555-5533 - 5773159633- 94KL13X - 49610011 - 50 - (made a call that lasted 45 seconds)
-- 514354 - Russel - (770) 555-1861 - 3592750733 - 322W7JE - 26013188 - 35 - (made a call that lasted 49 seconds)

SELECT people.license_plate, people.name FROM atm_transactions
JOIN courthouse_security_logs ON courthouse_security_logs.license_plate = people.license_plate
JOIN bank_accounts ON atm_transactions.account_number = bank_accounts.account_number
JOIN people ON bank_accounts.person_id = people.id
WHERE atm_transactions.atm_location = 'Fifer Street' AND atm_transactions.year = 2020 AND atm_transactions.month = 7 AND atm_transactions.day = 28 AND atm_transactions.transaction_type = 'withdraw' AND courthouse_security_logs.year = 2020 AND courthouse_security_logs.month = 7 AND courthouse_security_logs.day = 28 AND courthouse_security_logs.hour = 10 AND courthouse_security_logs.minute >= 15 AND courthouse_security_logs.minute <= 25 AND courthouse_security_logs.activity = 'exit';

-- match names and bank accounts

SELECT people.name, bank_accounts.account_number FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id;

-- Read phone records from after 10:15 a.m. as well as flight ticket purchases

SELECT * FROM phone_calls
WHERE year = 2020 AND month = 7 AND day = 28 AND duration <= 60 AND (caller = '(389) 555-519' OR caller = '(367) 555-5533' OR caller = '(829) 555-5269' OR caller = '(770) 555-1861');

-- fiftyville regional airport
-- id 8

SELECT * FROM airports
WHERE id = 7;

-- destinations
-- 7 (17:50) (DXB, Dubai International Airport, Dubai),
-- 5 (13:49) (DFS, Dallas/Fort Worth International Airport, Dalls)
-- 4 (20:16) (LHR, Heathrow Airport, London)
-- 5 (17:20) (DFS, Dallas/Fort Worth International Airport, Dalls)
-- 4 (16:16) (LHR, Heathrow Airport, London)


SELECT * FROM flights
WHERE year = 2020 AND month = 7 AND day = 29 AND origin_airport_id = 8;

-- get information about suspects
SELECT * FROM people
WHERE name LIKE '%Danielle%';
-- OR '%Bobby%' OR '%Madison%' OR '%Ernest%' OR 'Roy%' OR '%Elizabeth%' OR '%Victoria%' OR '%Russel%';

SELECT * FROM people
WHERE phone_number = '(375) 555-8161' OR phone_number = '(725) 555-3243';
