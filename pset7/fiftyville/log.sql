-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT description
FROM crime_scene_reports
WHERE month = 7 AND day = 28
AND street = "Chamberlin Street";
/*Result: Theft of the CS50 duck took place at 10:15am at
the Chamberlin Street courthouse. Interviews were conducted today
with three witnesses who were present at the
time — each of their interview transcripts mentions the courthouse.

useful info
time 10.15am
dat: 28th 07 2020
Chamberlin Street
3 witnesses? could they be suspects? where were they al 10.15am at the
28th of July?
*/


/*Crime scene reports after the even*/
/*Witnesses*/
SELECT day, month, year, description
FROM crime_scene_reports
WHERE day >= 1 AND month >= 7 AND year >= 2020
ORDER BY year, month, day ASC;
/* result:
28|7|2020|Theft of the CS50 duck took place at 10:15am at the
Chamberlin Street courthouse. Interviews were conducted today with three
witnesses who were present at the time — each of their interview
transcripts mentions the courthouse.
/*

----------------------------------------------------------------------------
/*what did the witnesses say? (interview was done the same day)*/
SELECT name, transcript
FROM interviews
WHERE month = 7 AND day = 28 AND year = 2020;

/* results:
Barbara| “You had my note?” he asked with a deep harsh voice and a strongly marked German accent. “I told you that I would call.” He looked from one to the other of us, as if uncertain which to address.

Ruth| Sometime within ten minutes of the theft,
I saw the thief get into a car in the courthouse parking lot and drive away.
If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.

Eugene| I don't know the thief's name, but it was someone I recognized.
Earlier this morning, before I arrived at the courthouse,
I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.

Raymond| As the thief was leaving the courthouse, they called someone who talked to them for less than a minute.
In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
The thief then asked the person on the other end of the phone to purchase the flight ticket.

|
V

look for a car that drove away 10 minutes after the theft(10:15am -> 10:20-25am ish) DONE

look for some that Eugene knows aand at that the morning of the theft withdrew money from an ATM at Fifer Street

look for phone calls that last  less than 1 mins, on the day of the theft about the same time he left the courthouse

look for earlies flights out of fiftyville on the 29th of july 2020
look for purchases of the flights above
------------------------------------------------------------------------------
look for a person's car that drove away 10 minutes after the theft(10:15am -> 10:20-25am ish)
*/
SELECT name, phone_number, passport_number, license_plate
FROM people
WHERE license_plate IN(
    SELECT license_plate
    FROM courthouse_security_logs
    WHERE activity = "exit" AND minute >= 15 AND minute <= 40 AND hour = 10 AND day = 28
    AND month = 7 AND year = 2020
);
/* RESULTS:
Patrick|(725) 555-4692|2963008352|5P2BI95
Amber|(301) 555-4174|7526138472|6P58WS2
Elizabeth|(829) 555-5269|7049073643|L93JTIZ
Roger|(130) 555-0289|1695452385|G412CB7
Madison|(286) 555-6063|1988161715|1106N58
Danielle|(389) 555-5198|8496433585|4328GD8
Russell|(770) 555-1861|3592750733|322W7JE
Evelyn|(499) 555-9472|8294398571|0NTHK55
Ernest|(367) 555-5533|5773159633|94KL13X
*/
------------------------------------
/* look for a person's bank account who made a transaction at the morning of the theft( 28/07/july)*/
SELECT name, license_plate
FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE bank_accounts.account_number IN(
    SELECT account_number
    FROM atm_transactions
    WHERE day = 28 AND month = 7 AND year=2020
    AND atm_location = "Fifer Street"
);

/*RESULTS
Ernest|94KL13X
Robert|I449449
Russell|322W7JE
Roy|QX4YZN3
Bobby|30G67EN
Elizabeth|L93JTIZ
Danielle|4328GD8
Madison|1106N58
Victoria|8X428L0
*/

/* join the two above results. You would have somebody who drove away from the courthouse 10 minutes after the theft, and at the same time the same morning
made a transaction*/
SELECT name, phone_number, passport_number, license_plate
FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE bank_accounts.account_number IN(
    SELECT account_number
    FROM atm_transactions
    WHERE day = 28 AND month = 7 AND year=2020
    AND atm_location = "Fifer Street"
) AND license_plate IN(
    SELECT license_plate
    FROM courthouse_security_logs
    WHERE activity = "exit" AND minute >= 15 AND minute <= 40 AND hour = 10 AND day = 28
    AND month = 7 AND year = 2020
);
/*Results:
Ernest|(367) 555-5533|5773159633|94KL13X
Russell|(770) 555-1861|3592750733|322W7JE
Elizabeth|(829) 555-5269|7049073643|L93JTIZ
Danielle|(389) 555-5198|8496433585|4328GD8
Madison|(286) 555-6063|1988161715|1106N58
*/

/*look for phone calls that last 1 mins on the day of the theft about the same time he left the courthouse*/
/* and these results with the queries above*/
SELECT caller, receiver
FROM phone_calls
WHERE day = 28 AND month = 7 AND year = 2020
AND duration <= 60 AND caller IN ()

SELECT name, phone_number, passport_number, license_plate
FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE bank_accounts.account_number IN(
    SELECT account_number
    FROM atm_transactions
    WHERE day = 28 AND month = 7 AND year=2020
    AND atm_location = "Fifer Street"
) AND license_plate IN(
    SELECT license_plate
    FROM courthouse_security_logs
    WHERE activity = "exit" AND minute >= 15 AND minute <= 40 AND hour = 10 AND day = 28
    AND month = 7 AND year = 2020
) AND phone_number IN(
    SELECT caller
    FROM phone_calls
    WHERE day = 28 AND month = 7 AND year = 2020
    AND duration <= 60
);
/*RESULTS:
Ernest|(367) 555-5533|5773159633|94KL13X
Russell|(770) 555-1861|3592750733|322W7JE
Madison|(286) 555-6063|1988161715|1106N58
*/

/*look for the passenger that took the earliest flight out of fiftyville on the 29th of july 2020, where the passengers are Ernest, Russel or Madison.*/
SELECT passport_number
FROM passengers
JOIN flights ON passengers.flight_id = flights.id
WHERE passport_number IN(
    SELECT passport_number
    FROM people
    WHERE name = "Ernest" OR name = "Russel" OR name = "Madison"
) AND flights.origin_airport_id IN (
    SELECT id
    FROM airports
    WHERE UPPER(city) = "FIFTYVILLE"
)AND flights.day = 29 AND flights.month = 7 AND flights.year = 2020;


SELECT hour, minute
FROM flights
WHERE origin_airport_id IN (
    SELECT id
    FROM airports
    WHERE UPPER(city) = "FIFTYVILLE"
)AND day = 29 AND month = 7 AND year = 2020 AND hour <= 12
ORDER BY hour, minute;
/*RESULT:
8|20
9|30
12|15

*/


-- These are the people
-- who exited the courthouse 10 minutes after the event
-- who made a call the same day that lasted for less than 1 minute
-- who took the first flight away from fiftyville the day after
SELECT name, phone_number, passport_number, license_plate
FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE bank_accounts.account_number IN(
    SELECT account_number
    FROM atm_transactions
    WHERE day = 28 AND month = 7 AND year=2020
    AND atm_location = "Fifer Street"
) AND license_plate IN(
    SELECT license_plate
    FROM courthouse_security_logs
    WHERE activity = "exit" AND minute >= 15 AND minute <= 40 AND hour = 10 AND day = 28
    AND month = 7 AND year = 2020
) AND phone_number IN(
    SELECT caller
    FROM phone_calls
    WHERE day = 28 AND month = 7 AND year = 2020
    AND duration <= 60
)AND passport_number IN(
    SELECT passport_number
    FROM passengers
    JOIN flights ON passengers.flight_id = flights.id
    WHERE passport_number IN(
        SELECT passport_number
        FROM people
        WHERE name = "Ernest" OR name = "Russel" OR name = "Madison"
    ) AND flights.origin_airport_id IN (
        SELECT id
        FROM airports
        WHERE UPPER(city) = "FIFTYVILLE"
    )AND flights.day = 29 AND flights.month = 7 AND flights.year = 2020 AND flights.hour <= 12 AND hour = 8 AND minute = 20
);

/*RESULT:
Ernest|(367) 555-5533|5773159633|94KL13X
Madison|(286) 555-6063|1988161715|1106N58
*/

SELECT name, phone_number, passport_number, license_plate
FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE name = "Ernest" OR name = "Madison" AND ban

SELECT amount, transaction_type
FROM atm_transactions
WHERE account_number IN(
    SELECT account_number
    FROM bank_accounts
    JOIN people ON bank_accounts.person_id = people.id
    WHERE name = "Ernest"
) AND day = 28 AND month = 7 AND year = 2020 AND atm_location = "Fifer Street";


SELECT amount, transaction_type
FROM atm_transactions
WHERE account_number IN(
    SELECT account_number
    FROM bank_accounts
    JOIN people ON bank_accounts.person_id = people.id
    WHERE name = "Madison"
) AND day = 28 AND month = 7 AND year = 2020 AND atm_location = "Fifer Street";




SELECT name
FROM people
WHERE phone_number = (
    SELECT receiver
    FROM phone_calls
    WHERE day = 28 AND month = 7 AND year = 2020
    AND duration <= 60 AND caller = (
        SELECT phone_number
        FROM people
        WHERE name = "Ernest"
    )
); -- Ernest called Berthold


SELECT name
FROM people
WHERE phone_number = (
    SELECT receiver
    FROM phone_calls
    WHERE day = 28 AND month = 7 AND year = 2020
    AND duration <= 60 AND caller = (
        SELECT phone_number
        FROM people
        WHERE name = "Madison"
    )
); -- Madison called James

SELECT name
FROM people
WHERE passport_number IN(
    SELECT passport_number
    FROM passengers
    JOIN flights ON passengers.flight_id = flights.id
    WHERE flights.origin_airport_id IN (
        SELECT id
        FROM airports
        WHERE UPPER(city) = "FIFTYVILLE"
    )AND flights.day = 29 AND flights.month = 7 AND flights.year = 2020 AND flights.hour <= 12 AND hour = 8 AND minute = 20
);
-- Neither Jamer nor Berthold is in the flight


SELECT day, month, year, amount, transaction_type
FROM atm_transactions
WHERE account_number IN (
    SELECT account_number
    FROM bank_accounts
    JOIN people ON people.id = bank_accounts.person_id
    WHERE people.name = "James"
) AND month = 7 AND year=2020;
/*James doesn't have a ba this means that Berthold can be the only accomplice*/
/*Considering Ernest called Berthold the day of the thief I'm gonna go with them */

SELECT day, month, year, amount, transaction_type
FROM atm_transactions
WHERE account_number IN (
    SELECT account_number
    FROM bank_accounts
    JOIN people ON people.id = bank_accounts.person_id
    WHERE people.name = "Berthold"
) AND month = 7 AND year=2020;

SELECT amount, transaction_type
FROM atm_transactions
WHERE day = 28 AND month = 7 AND year=2020
AND atm_location = "Fifer Street"
AND account_number IN (
    SELECT account_number
    FROM bank_accounts
    JOIN people ON people.id = bank_accounts.person_id
    WHERE people.name = "Ernest"
); -- he withdrew 50


SELECT full_name
FROM airports
WHERE id IN (
    SELECT destination_airport_id
    FROM flights
    WHERE origin_airport_id = (
        SELECT id
        FROM airports
        WHERE UPPER(city) = "FIFTYVILLE"
    )AND flights.day = 29 AND flights.month = 7 AND flights.year = 2020 AND flights.hour <= 12 AND hour = 8 AND minute = 20
);
-- The thief went to Heathrow Airport, in the city of London
SELECT city
FROM airports
WHERE UPPER(full_name) LIKE "%HEATHROW%";
--London
/*
airports                  crime_scene_reports       people
atm_transactions          flights                   phone_calls
bank_accounts             interviews
courthouse_security_logs  passengers

CREATE TABLE crime_scene_reports (
    id INTEGER,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    street TEXT,
    description TEXT,
    PRIMARY KEY(id)
);
CREATE TABLE interviews (
    id INTEGER,
    name TEXT,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    transcript TEXT,
    PRIMARY KEY(id)
);
CREATE TABLE courthouse_security_logs (
    id INTEGER,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    hour INTEGER,
    minute INTEGER,
    activity TEXT,
    license_plate TEXT,
    PRIMARY KEY(id)
);
CREATE TABLE atm_transactions (
    id INTEGER,
    account_number INTEGER,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    atm_location TEXT,
    transaction_type TEXT,
    amount INTEGER,
    PRIMARY KEY(id)
);
CREATE TABLE bank_accounts (
    account_number INTEGER,
    person_id INTEGER,
    creation_year INTEGER,
    FOREIGN KEY(person_id) REFERENCES people(id)
);
CREATE TABLE airports (
    id INTEGER,
    abbreviation TEXT,
    full_name TEXT,
    city TEXT,
    PRIMARY KEY(id)
);
CREATE TABLE flights (
    id INTEGER,
    origin_airport_id INTEGER,
    destination_airport_id INTEGER,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    hour INTEGER,
    minute INTEGER,
    PRIMARY KEY(id),
    FOREIGN KEY(origin_airport_id) REFERENCES airports(id),
    FOREIGN KEY(destination_airport_id) REFERENCES airports(id)
);
CREATE TABLE passengers (
    flight_id INTEGER,
    passport_number INTEGER,
    seat TEXT,
    FOREIGN KEY(flight_id) REFERENCES flights(id)
);
CREATE TABLE phone_calls (
    id INTEGER,
    caller TEXT,
    receiver TEXT,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    duration INTEGER,
    PRIMARY KEY(id)
);
CREATE TABLE people (
    id INTEGER,
    name TEXT,
    phone_number TEXT,
    passport_number INTEGER,
    license_plate TEXT,
    PRIMARY KEY(id)
);
*/