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

class PageLogin extends PageBase
{
	function __construct()
	{ 
		
	}
	
	function runPage()
	{
		$subpages = WebRequest::getSubpages();
		if(isset($subpages[1]))
		{
			if($subpages[1] == 'Register')
			{
				$this->runRegister();
			}
			else if($subpages[1] == 'Forgot')
			{
				$this->runForgotPw();
			}
		}
		else
		{
			$this->runLogin();
		}
	}
	
	function runLogin()
	{
		$this->subtitle="Login";
		
		if(WebRequest::wasPosted())
		{
			if(User::authenticate(WebRequest::getString('username'),WebRequest::getString('password')))
				WebRequest::redirect('');
		}
		else
		{
			$this->smarty->assign('subpage', 'page/LoginForm.tpl');
		}
	}
	
	function runRegister()
	{
		$this->subtitle="Register for a Tool Account";
		
		if(WebRequest::wasPosted())
		{
			if(User::authenticate(WebRequest::getString('username'),WebRequest::getString('password')))
				WebRequest::redirect('');
		}
		else
		{
			$this->smarty->assign('subpage', 'page/RegisterForm.tpl');
		}
	}
	
	function runForgotPw()
	{
		$this->subtitle="Forgotten your password?";
		$this->smarty->assign('subpage', 'page/ForgotPwForm.tpl');
	}
}