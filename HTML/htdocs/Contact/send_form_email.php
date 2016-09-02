<?php
//created by Elliot Chibe - 08/05/15

//subject and email variables
$emailSubject = 'New comment from elliotchibe.com!';
$webMaster = 'elliotchibe@yahoo.com';

//Gathering data variables
$name = $_POST['name'];
$email = $_POST['email'];
$message = $_POST['message'];


$body = <<<EOD
<br><hr><br>
Name: $name <br>
Email Address: $email <br>
Message: $message <br>
EOD;

//format email
$headers .= "Content-type: text/html\r\n";
$success = mail($webMaster, $emailSubject, $body, $headers);

//success page
$results = <<<EOD
<html>
<head>
<title>Order success!</title>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
<style type="text/css">

</style>
</head>

<div>
<div align = "left">I will get back to you soon!</div>
</div>
</body>

</html>
EOD;
echo "$results";
	
?>