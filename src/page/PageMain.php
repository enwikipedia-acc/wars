<?php
/**************************************************************************
*                     Wikipedia Account Request System                    *
***************************************************************************
*                                                                         *
* Conceptualised by Incubez (author: X!) and ACC (author: SQL and others) *
*                                                                         *
* Please refer to /LICENCE for more info.                                 *
*                                                                         *
**************************************************************************/

/**************************************************************************
* Please note: This file was originally written by Simon Walker for a     *
* university assignment, and may need adapting for purpose.               *
*                                                                         *
* DO NOT CHANGE THE EXISTING INTERFACE OF THIS CLASS unless you really    *
* know what you're doing.                                                 *
**************************************************************************/

// check that this code is being called from a valid entry point. 
if(!defined("WARS"))
	die("Invalid code entry point!");

class PageMain extends PageBase
{
	function __construct()
	{
		$this->subtitle = "Account Requests";
	}
	
	function runPage()
	{
		$this->smarty->assign('subpage', 'page/MainPage.tpl');
		$this->smarty->assign('req_open', Request::query(array(
			REQUEST_COLUMN_STATUS => REQUEST_STATUS_OPEN,
			REQUEST_COLUMN_MAILCONFIRM => "Confirmed"
			)));
		$this->smarty->assign('req_flagged', Request::query(array(
			REQUEST_COLUMN_STATUS => REQUEST_STATUS_FLAGGEDUSER,
			REQUEST_COLUMN_MAILCONFIRM => "Confirmed"
			)));
		$this->smarty->assign('req_checkuser', Request::query(array(
			REQUEST_COLUMN_STATUS => REQUEST_STATUS_CHECKUSER,
			REQUEST_COLUMN_MAILCONFIRM => "Confirmed"
			)));
				
	}
}