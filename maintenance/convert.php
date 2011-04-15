<?php
define("WARS", 1);
require_once 'config.inc.php';

$olddatabase = "p_acc_sand";

require_once $baseMaintenancePath . 'convert.inc';

out("This script will convert an ACC-style database into a WARS database.");
out("Please ^C in 10 seconds if you do not wish to translate $olddatabase");
out("into $db_name_a .");
for ($i = 10; $i > 0; $i--) {
	out($i);
	sleep(1);
}

/*
 * Stage zero: Set up the environment
 */



/*
 * Stage one: Create database tables
 */

out("Stage one: Create database tables");

foreach ($tables_sql as $key => $value)
{
	out("  - $key");
	$result = $accDatabase->query($value);
	if(get_class($result) != "PDOStatement")
	{
		out("Error! Could not retrieve result!");
		echo $value;
		die();
	}
	$error = $result->errorInfo();
	if($error[0] != "0000")
	{
		print_r($error);
		die;
	}
	out("    Done!");
}

/*
 * Stage two: Add existing simple data:
 *  * user
 *  * pend
 *  * template
 *  * emails
 */
 
out("Stage two: Add existing simple data");

out("  - acc_user");
$result = $accDatabase->query("INSERT INTO acc_user SELECT user_id, user_name, user_email, user_pass, user_level, user_onwikiname, user_welcome_sig, user_lastactive, user_lastip, user_forcelogout, user_secure, user_checkuser, user_identified, user_welcome_templateid, user_abortpref, user_confirmationdiff FROM $olddatabase.acc_user; ");
if(get_class($result) != "PDOStatement")
{
	out("Error! Could not retrieve result!");
	echo $value;
	die();
}
$error = $result->errorInfo();
if($error[0] != "0000")
{
	print_r($error);
	die;
}
out("    Done!");

out("  - acc_pend");
$result = $accDatabase->query("INSERT INTO acc_pend SELECT * FROM $olddatabase.acc_pend;");
if(get_class($result) != "PDOStatement")
{
	out("Error! Could not retrieve result!");
	echo $value;
	die();
}
$error = $result->errorInfo();
if($error[0] != "0000")
{
	print_r($error);
	die;
}
out("    Done!");

out("  - acc_template");
$result = $accDatabase->query("INSERT INTO acc_template SELECT * FROM $olddatabase.acc_template;");
if(get_class($result) != "PDOStatement")
{
	out("Error! Could not retrieve result!");
	echo $value;
	die();
}
$error = $result->errorInfo();
if($error[0] != "0000")
{
	print_r($error);
	die;
}
out("    Done!");

out("  - acc_emails");
$result = $accDatabase->query("INSERT INTO acc_emails SELECT * FROM $olddatabase.acc_emails;");
if(get_class($result) != "PDOStatement")
{
	out("Error! Could not retrieve result!");
	echo $value;
	die();
}
$error = $result->errorInfo();
if($error[0] != "0000")
{
	print_r($error);
	die;
}
out("    Done!");

/*
 * Stage three: Add partially calculated dependant data:
 *  * welcome
 *  * log
 *  * ban
 *  * cmt
 */
 
/*
 * Stage four: Add fully calculated data (run maintenance scripts)
 *  * trusted ips
 *  * titleblacklist
 */
 
/*
 * Stage five: Add indices, foreign keys, and other assorted produce
 */