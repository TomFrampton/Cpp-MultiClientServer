-- phpMyAdmin SQL Dump
-- version 3.5.2.2
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Mar 08, 2013 at 12:15 PM
-- Server version: 5.5.27
-- PHP Version: 5.4.7

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `oosd`
--

-- --------------------------------------------------------

--
-- Table structure for table `employee`
--

DROP TABLE IF EXISTS `employee`;
CREATE TABLE IF NOT EXISTS `employee` (
  `employeeID` int(5) unsigned NOT NULL AUTO_INCREMENT,
  `forename` varchar(30) NOT NULL,
  `surname` varchar(30) NOT NULL,
  `position` varchar(20) NOT NULL,
  `healthClubID` int(5) unsigned NOT NULL,
  PRIMARY KEY (`employeeID`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `healthclub`
--

DROP TABLE IF EXISTS `healthclub`;
CREATE TABLE IF NOT EXISTS `healthclub` (
  `healthClubID` int(5) unsigned NOT NULL AUTO_INCREMENT,
  PRIMARY KEY (`healthClubID`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `healthdata`
--

DROP TABLE IF EXISTS `healthdata`;
CREATE TABLE IF NOT EXISTS `healthdata` (
  `membershipID` int(5) unsigned NOT NULL,
  `timeRecorded` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `height` int(5) unsigned NOT NULL,
  `weight` int(5) unsigned NOT NULL,
  PRIMARY KEY (`membershipID`,`timeRecorded`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `member`
--

DROP TABLE IF EXISTS `member`;
CREATE TABLE IF NOT EXISTS `member` (
  `membershipID` int(5) unsigned NOT NULL AUTO_INCREMENT,
  `forename` varchar(30) NOT NULL,
  `surname` varchar(30) NOT NULL,
  `gender` enum('M','F') NOT NULL,
  `healthClubID` int(5) unsigned NOT NULL,
  PRIMARY KEY (`membershipID`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `trainingmeeting`
--

DROP TABLE IF EXISTS `trainingmeeting`;
CREATE TABLE IF NOT EXISTS `trainingmeeting` (
  `membershipID` int(5) unsigned NOT NULL,
  `meetingTime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `employeeID` int(5) unsigned NOT NULL,
  `waitingTime` int(5) unsigned NOT NULL,
  `meetingType` enum('PRE','POST') DEFAULT NULL,
  PRIMARY KEY (`membershipID`,`meetingTime`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
