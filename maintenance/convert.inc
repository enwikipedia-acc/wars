<?php 

$tables_sql = array( 'acc_trustedips' => <<<SQL
CREATE  TABLE  `acc_trustedips` (
  `trustedips_ipaddr` VARCHAR(15) NOT NULL ,
  PRIMARY KEY (`trustedips_ipaddr`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = latin1
SQL
, 'acc_titleblacklist' => <<<SQL
CREATE  TABLE  `acc_titleblacklist` (
  `titleblacklist_regex` VARCHAR(128) NOT NULL ,
  `titleblacklist_casesensitive` TINYINT(1) NOT NULL ,
  PRIMARY KEY (`titleblacklist_regex`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = latin1
SQL
, 'acc_welcomequeue' => <<<SQL
CREATE  TABLE  `acc_welcomequeue` (
  `welcomequeue_id` INT(11) NOT NULL AUTO_INCREMENT ,
  `welcomequeue_uid` INT NOT NULL DEFAULT 0 COMMENT 'Username of the welcoming user' ,
  `welcomequeue_user` VARCHAR(1024) NOT NULL ,
  `welcomequeue_status` VARCHAR(96) NOT NULL ,
  PRIMARY KEY (`welcomequeue_id`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = latin1
SQL
, 'acc_ban' => <<<SQL
CREATE  TABLE  `acc_ban` (
  `ban_id` INT(11) NOT NULL AUTO_INCREMENT ,
  `ban_type` VARCHAR(255) NOT NULL ,
  `ban_target` VARCHAR(700) NOT NULL ,
  `ban_user` INT NOT NULL ,
  `ban_reason` VARCHAR(4096) NOT NULL ,
  `ban_date` VARCHAR(1024) NOT NULL ,
  `ban_duration` VARCHAR(255) NOT NULL ,
  `ban_active` TINYINT(1) NOT NULL DEFAULT '1' ,
  PRIMARY KEY (`ban_id`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = latin1
SQL
, 'acc_welcometemplate' => <<<SQL
CREATE  TABLE  `acc_welcometemplate` (
  `welcometemplate_id` INT(11) NOT NULL AUTO_INCREMENT ,
  `welcometemplate_usercode` TINYTEXT NOT NULL ,
  `welcometemplate_botcode` TINYTEXT NOT NULL ,
  PRIMARY KEY (`welcometemplate_id`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = latin1
SQL
, 'acc_user' => <<<SQL
CREATE  TABLE  `acc_user` (
  `user_id` INT(11) NOT NULL AUTO_INCREMENT ,
  `user_name` VARCHAR(255) NOT NULL ,
  `user_email` VARCHAR(255) NOT NULL ,
  `user_pass` VARCHAR(255) NOT NULL ,
  `user_level` VARCHAR(255) NOT NULL DEFAULT 'New' ,
  `user_onwikiname` VARCHAR(255) NOT NULL ,
  `user_welcome_sig` VARCHAR(4096) NOT NULL DEFAULT '' ,
  `user_lastactive` DATETIME NOT NULL DEFAULT '0000-00-00 00:00:00' ,
  `user_lastip` VARCHAR(40) CHARACTER SET 'utf8' NOT NULL DEFAULT '0.0.0.0' ,
  `user_forcelogout` INT(3) NOT NULL DEFAULT '0' ,
  `user_secure` INT(11) NOT NULL DEFAULT '0' ,
  `user_checkuser` INT(1) NOT NULL DEFAULT '0' ,
  `user_identified` INT(1) UNSIGNED NOT NULL DEFAULT '0' ,
  `user_welcome_templateid` INT(11) NOT NULL DEFAULT '0' ,
  `user_abortpref` TINYINT(4) NOT NULL DEFAULT '0' ,
  `user_confirmationdiff` INT(10) UNSIGNED NOT NULL DEFAULT '0' ,
  PRIMARY KEY (`user_id`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = latin1
SQL
, 'acc_message' => <<<SQL
CREATE  TABLE  `acc_message` (
  `message_id` INT(11) NOT NULL AUTO_INCREMENT ,
  `message_text` BLOB NOT NULL ,
  `message_count` INT(11) NOT NULL ,
  `message_desc` VARCHAR(255) NOT NULL ,
  `message_type` VARCHAR(255) NOT NULL ,
  `message_key` VARCHAR(45) NOT NULL ,
  PRIMARY KEY (`message_id`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = latin1
SQL
, 'acc_request' => <<<SQL
CREATE  TABLE  `acc_request` (
  `request_id` INT(11) NOT NULL AUTO_INCREMENT ,
  `request_email` VARCHAR(512) NOT NULL ,
  `request_ip` VARCHAR(255) NOT NULL ,
  `request_name` VARCHAR(512) NOT NULL ,
  `request_cmt` MEDIUMTEXT NOT NULL ,
  `request_status` VARCHAR(255) NOT NULL ,
  `request_date` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP ,
  `request_checksum` VARCHAR(256) NOT NULL ,
  `request_emailsent` VARCHAR(10) NOT NULL ,
  `request_mailconfirm` VARCHAR(255) NOT NULL ,
  `request_reserved` INT(11) NOT NULL DEFAULT '0' COMMENT 'User ID of user who has \"reserved\" this request' ,
  `request_useragent` BLOB NOT NULL COMMENT 'Useragent of the requesting web browser' ,
  `request_proxyip` VARCHAR(255) NULL DEFAULT NULL ,
  PRIMARY KEY (`request_id`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = latin1
SQL
, 'acc_log' => <<<SQL
CREATE  TABLE  `acc_log` (
  `log_id` INT(11) NOT NULL AUTO_INCREMENT ,
  `log_target_id` INT NOT NULL DEFAULT 0 ,
  `log_target_objecttype` VARCHAR(45) NULL ,
  `log_target_text` VARCHAR(255) NOT NULL ,
  `log_user_id` INT NOT NULL DEFAULT 0 ,
  `log_user_text` VARCHAR(255) NOT NULL ,
  `log_action` VARCHAR(255) NOT NULL ,
  `log_time` DATETIME NOT NULL ,
  `log_cmt` BLOB NOT NULL ,
  PRIMARY KEY (`log_id`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = latin1
SQL
, 'acc_comment' => <<<SQL
CREATE  TABLE  `acc_comment` (
  `comment_id` INT(11) NOT NULL AUTO_INCREMENT ,
  `comment_time` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP ,
  `comment_user` INT NOT NULL DEFAULT 0 ,
  `comment_comment` MEDIUMTEXT NOT NULL ,
  `comment_visibility` VARCHAR(255) NOT NULL ,
  `comment_request` INT(11) NOT NULL ,
  PRIMARY KEY (`comment_id`) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8
SQL
);

$backup = array(
"DROP DATABASE IF EXISTS ".$olddatabase."_backup;",
"CREATE DATABASE ".$olddatabase."_backup;",
"CREATE TABLE ".$olddatabase."_backup.acc_ban LIKE $olddatabase.acc_ban;",
"CREATE TABLE ".$olddatabase."_backup.acc_cmt LIKE $olddatabase.acc_cmt;",
"CREATE TABLE ".$olddatabase."_backup.acc_emails LIKE $olddatabase.acc_emails;",
"CREATE TABLE ".$olddatabase."_backup.acc_log LIKE $olddatabase.acc_log;",
"CREATE TABLE ".$olddatabase."_backup.acc_pend LIKE $olddatabase.acc_pend;",
"CREATE TABLE ".$olddatabase."_backup.acc_template LIKE $olddatabase.acc_template;",
"CREATE TABLE ".$olddatabase."_backup.acc_titleblacklist LIKE $olddatabase.acc_titleblacklist;",
"CREATE TABLE ".$olddatabase."_backup.acc_trustedips LIKE $olddatabase.acc_trustedips;",
"CREATE TABLE ".$olddatabase."_backup.acc_user LIKE $olddatabase.acc_user;",
"CREATE TABLE ".$olddatabase."_backup.acc_welcome LIKE $olddatabase.acc_welcome;",

"LOCK TABLES $olddatabase.acc_ban WRITE, $olddatabase.acc_cmt WRITE, $olddatabase.acc_emails WRITE, 
	$olddatabase.acc_log WRITE, $olddatabase.acc_pend WRITE, $olddatabase.acc_template WRITE, 
	$olddatabase.acc_titleblacklist WRITE, $olddatabase.acc_trustedips WRITE, $olddatabase.acc_user WRITE, 
	$olddatabase.acc_welcome WRITE, ".$olddatabase."_backup.acc_ban WRITE, 
	".$olddatabase."_backup.acc_cmt WRITE, ".$olddatabase."_backup.acc_emails WRITE, 
	".$olddatabase."_backup.acc_log WRITE, ".$olddatabase."_backup.acc_pend WRITE, 
	".$olddatabase."_backup.acc_template WRITE, ".$olddatabase."_backup.acc_titleblacklist WRITE, 
	".$olddatabase."_backup.acc_trustedips WRITE, ".$olddatabase."_backup.acc_user WRITE, 
	".$olddatabase."_backup.acc_welcome WRITE,
	acc_trustedips WRITE, acc_titleblacklist WRITE, acc_welcomequeue WRITE, acc_ban WRITE,
	acc_welcometemplate WRITE, acc_user WRITE, acc_message WRITE, acc_request WRITE, acc_log WRITE,
	acc_comment WRITE;",

"INSERT INTO ".$olddatabase."_backup.acc_ban SELECT * FROM $olddatabase.acc_ban;",
"INSERT INTO ".$olddatabase."_backup.acc_cmt SELECT * FROM $olddatabase.acc_cmt;",
"INSERT INTO ".$olddatabase."_backup.acc_emails SELECT * FROM $olddatabase.acc_emails;",
"INSERT INTO ".$olddatabase."_backup.acc_log SELECT * FROM $olddatabase.acc_log;",
"INSERT INTO ".$olddatabase."_backup.acc_pend SELECT * FROM $olddatabase.acc_pend;",
"INSERT INTO ".$olddatabase."_backup.acc_template SELECT * FROM $olddatabase.acc_template;",
"INSERT INTO ".$olddatabase."_backup.acc_titleblacklist SELECT * FROM $olddatabase.acc_titleblacklist;",
"INSERT INTO ".$olddatabase."_backup.acc_trustedips SELECT * FROM $olddatabase.acc_trustedips;",
"INSERT INTO ".$olddatabase."_backup.acc_user SELECT * FROM $olddatabase.acc_user;",
"INSERT INTO ".$olddatabase."_backup.acc_welcome SELECT * FROM $olddatabase.acc_welcome;",

);

$pre_transform = array(
"ALTER TABLE $olddatabase.acc_log ADD COLUMN `log_user_id` INT NULL  AFTER `log_cmt` , ADD COLUMN `log_user_text` VARCHAR(255) NULL  AFTER `log_user_id` , ADD COLUMN `log_target_id` INT NULL  AFTER `log_user_text` , ADD COLUMN `log_target_object` VARCHAR(45) NULL  AFTER `log_target_id` , ADD COLUMN `log_target_text` VARCHAR(255) NULL  AFTER `log_target_object` ;",
"SET SQL_SAFE_UPDATES=0;",
"update $olddatabase.acc_log set log_user_text = log_user;",
"update $olddatabase.acc_log set log_target_object = 'user', log_target_id = log_pend where log_action = 'Approved';",
"update $olddatabase.acc_log set log_target_object = 'ban', log_target_text = log_pend where log_action = 'Banned';",
"delete from $olddatabase.acc_log where log_action = 'Blacklist Hit';",
"update $olddatabase.acc_log set log_target_object = 'request', log_target_id = log_pend where log_action = 'BreakReserve';",
"delete from $olddatabase.acc_log where log_action = 'Closed';",
"update $olddatabase.acc_log set log_target_object = 'request', log_target_id = log_pend where log_action  like 'Closed %';",
"update $olddatabase.acc_log set log_action = 'Deferred to flagged users' where log_action = 'Deferred to admins';",
"update $olddatabase.acc_log set log_target_object = 'request', log_target_id = log_pend where log_action like 'Deferred to%';",
"update $olddatabase.acc_log set log_target_object = 'request', log_target_id = log_pend where log_action = 'Email Confirmed';",
"delete from $olddatabase.acc_log where log_action = 'DNSBL Hit';",
"update $olddatabase.acc_log set log_target_object = 'request', log_target_id = log_pend where log_action = 'Reserved';",
"update $olddatabase.acc_log set log_target_object = 'request', log_target_id = log_pend where log_action = 'Unreserved';",
"delete from $olddatabase.acc_log where log_action = 'badpass';",
"update $olddatabase.acc_log set log_target_object = 'user', log_target_id = log_pend where log_action = 'Declined';",
"update $olddatabase.acc_log set log_target_object = 'user', log_target_id = log_pend where log_action = 'Demoted';",
"update $olddatabase.acc_log set log_target_object = 'user', log_target_id = log_pend where log_action = 'Promoted';",
"update $olddatabase.acc_log set log_target_object = 'user', log_target_id = log_pend where log_action = 'Suspended';",
"update $olddatabase.acc_log set log_target_object = 'message', log_target_id = log_pend where log_action = 'Edited';",
"update $olddatabase.acc_log set log_target_object = 'ban', log_target_id = log_pend where log_action = 'Unbanned';",
"update $olddatabase.acc_log set log_target_object = 'user', log_target_id = log_pend where log_action = 'Prefchange';",
"update $olddatabase.acc_log set log_target_object = 'user', log_target_id = log_pend where log_action = 'Renamed';",
"update $olddatabase.acc_log set log_target_object = 'template', log_target_id = log_pend where log_action = 'CreatedTemplate';",
"update $olddatabase.acc_log set log_target_object = 'template', log_target_id = log_pend where log_action = 'DeletedTemplate';",
"update $olddatabase.acc_log set log_target_object = 'template', log_target_id = log_pend where log_action = 'EditedTemplate';",
"update $olddatabase.acc_log set log_action = 'Closed Dropped' where log_action = 'Closed 0';",
"update $olddatabase.acc_log set log_action = 'Closed Created' where log_action = 'Closed 1';",
"update $olddatabase.acc_log set log_action = 'Closed Similar' where log_action = 'Closed 2';",
"update $olddatabase.acc_log set log_action = 'Closed Taken' where log_action = 'Closed 3';",
"update $olddatabase.acc_log set log_action = 'Closed UPolicy' where log_action = 'Closed 4';",
"update $olddatabase.acc_log set log_action = 'Closed Technical' where log_action = 'Closed 5';",
"update $olddatabase.acc_log set log_action = 'Closed SUL Taken' where log_action = 'Closed 26';",
"update $olddatabase.acc_log set log_action = 'Closed Password Reset' where log_action = 'Closed 30';",
);

$post_transform = array(
"UPDATE acc_request SET request_status = 'New' where request_mailconfirm != 'Confirmed' and request_status = 'Open';",
"UPDATE acc_message SET message_key='m-created' WHERE message_id='1';",
"UPDATE acc_message SET message_key='m-similar' WHERE message_id='2';",
"UPDATE acc_message SET message_key='m-taken' WHERE message_id='3';",
"UPDATE acc_message SET message_key='m-upol' WHERE message_id='4';",
"UPDATE acc_message SET message_key='m-impossible' WHERE message_id='5';",
"DELETE FROM acc_message WHERE message_id='6';",
"DELETE FROM acc_message WHERE message_id='7';",
"DELETE FROM acc_message WHERE message_id='8';",
"DELETE FROM acc_message WHERE message_id='9';",
"DELETE FROM acc_message WHERE message_id='10';",
"DELETE FROM acc_message WHERE message_id='11';",
"DELETE FROM acc_message WHERE message_id='12';",
"DELETE FROM acc_message WHERE message_id='13';",
"DELETE FROM acc_message WHERE message_id='14';",
"DELETE FROM acc_message WHERE message_id='15';",
"DELETE FROM acc_message WHERE message_id='16';",
"DELETE FROM acc_message WHERE message_id='17';",
"DELETE FROM acc_message WHERE message_id='18';",
"DELETE FROM acc_message WHERE message_id='19';",
"DELETE FROM acc_message WHERE message_id='20';",
"DELETE FROM acc_message WHERE message_id='21';",
"DELETE FROM acc_message WHERE message_id='22';",
"DELETE FROM acc_message WHERE message_id='23';",
"DELETE FROM acc_message WHERE message_id='24';",
"UPDATE acc_message SET message_key='m-sul' WHERE message_id='26';",
"DELETE FROM acc_message WHERE message_id='27';",
"DELETE FROM acc_message WHERE message_id='28';",
"DELETE FROM acc_message WHERE message_id='29';",
"UPDATE acc_message SET message_key='m-password' WHERE message_id='30';",
"UPDATE acc_message SET message_key='sitenotice' WHERE message_id='31';",
"UPDATE acc_message SET message_key='abort-config' WHERE message_id='32';",
);

function out($text, $newline=TRUE)
{
	$lines = split("[\n|\r]", $text);
	foreach ($lines as $value) {
		echo ($newline?date('c') . "  : ":"")  . $value . ($newline?"\n":"");
	}
}

$querycount = 0;

function query($q)
{
	global $accDatabase, $querycount;
	$result = $accDatabase->query($q);
	$querycount++;
	$error = $accDatabase->errorInfo();
	if($error[0] != "0000")
	{
		print_r($error);
		die;
	}	
}
function pause()
{
	//out("Press enter to continue...");
	//fgets(STDIN);	
}