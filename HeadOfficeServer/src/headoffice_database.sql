DROP TABLE IF EXISTS member;
CREATE TABLE member (
	membershipID INT(5) UNSIGNED NOT NULL PRIMARY KEY AUTO_INCREMENT,
	forename VARCHAR(30) NOT NULL,
	surname VARCHAR(30) NOT NULL,
	gender ENUM('M','F') NOT NULL,
	healthClubID INT(5) UNSIGNED NOT NULL
);

DROP TABLE IF EXISTS employee;
CREATE TABLE employee (
	employeeID INT(5) UNSIGNED NOT NULL PRIMARY KEY AUTO_INCREMENT,
	forename VARCHAR(30) NOT NULL,
	surname VARCHAR(30) NOT NULL,
	position VARCHAR(20) NOT NULL,
	healthClubID INT(5) UNSIGNED NOT NULL
);

DROP TABLE IF EXISTS trainingMeeting;
CREATE TABLE trainingMeeting (
	membershipID INT(5) UNSIGNED NOT NULL,
	meetingTime TIMESTAMP NOT NULL,
	employeeID INT(5) UNSIGNED  NOT NULL,
	waitingTime INT(5) UNSIGNED NOT NULL,
	meetingType ENUM('PRE', 'POST'),
	PRIMARY KEY(membershipID, meetingTime) 
);

DROP TABLE IF EXISTS healthData;
CREATE TABLE healthData (
	membershipID INT(5) UNSIGNED NOT NULL,
	timeRecorded TIMESTAMP NOT NULL,
	height INT(5) UNSIGNED NOT NULL,
	weight INT(5) UNSIGNED NOT NULL,
	PRIMARY KEY(membershipID, timeRecorded)
);

DROP TABLE IF EXISTS healthClub;
CREATE TABLE healthClub (
	healthClubID INT(5) UNSIGNED NOT NULL PRIMARY KEY AUTO_INCREMENT
);


