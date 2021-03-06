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

class PageForward extends PageBase
{
	private $linkedRequest = null;
	
	function __construct()
	{
		if(WebRequest::getInt("id") != 0)
			$this->linkedRequest = Request::getById();	
	}
	
	function runPage()
	{
		if($this->linkedRequest == null || $this->linkedRequest->isAvailableForCurrentUser())
			WebRequest::redirectUrl(WebRequest::getString('link'));
	}
}