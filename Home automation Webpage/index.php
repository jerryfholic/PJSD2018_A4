<!DOCTYPE HTML>
<html>
	<head>
		<title>Home automation</title>
		<link rel="stylesheet" type="text/css" href="CSS.css"/>
	</head>
<body>
		<ul>
			<li><a class="active" href="index.php">Timothy</a></li>
			<li><a href="Bewaker.html">Gaurd</a></li>
			<li><a href="Verpleegster.html">Nurse</a></li>
		</ul>
		
			<main>
				<h1> Home Automation System for Timothy </h1>

<?php
	$jsonFile = fopen("/home/pi/Documents/PHP_CPP_COMM.json", r) or die("Unable to open file");
	$jsonString = fread($jsonFile, filesize("/home/pi/Documents/PHP_CPP_COMM.json"));
	fclose($jsonFile);
	
	$jsonObject = json_decode($jsonString);
	//var_dump($jsonObject);
?>

<p>
	Potmeter value: <?php echo $jsonObject->{'Potmeter'} ?><br>
	ToggleLed value: <?php echo $jsonObject->{'ToggleLed'} ?><br>
	<form method="post">
		<input type="submit" name="ToggleLed" id="ToggleLed" value="Toggle Lamp Led" />
		<input type="submit" name="ToggleLed" id="ToggleLed" value="Toggle Bed Led" />
		<input type="submit" name="ToggleLed" id="ToggleLed" value="Toggle Raam Venster Led" />
		<input type="submit" name="ToggleLed" id="ToggleLed" value="Toggle Raam Led-strip" />
		<input type="submit" name="ToggleLed" id="ToggleLed" value="Toggle Deur Led" /><br>
	</form>
</p>

<?php
	if(array_key_exists('ToggleLed', $_POST)){
		test($jsonObject);
	}
		
	function test($jsonObject) {
		if ($jsonObject->{'ToggleLed'}) {
			$jsonObject->{'ToggleLed'} = 0;
		} else {
			$jsonObject->{'ToggleLed'} = 1;
		}
		//var_dump($jsonObject);
		$jsonOutString = json_encode($jsonObject);
		$jsonOut = fopen("/home/pi/Documents/PHP_CPP_COMM.json", "w" ) or die("Unable to open file");		
		fwrite($jsonOut, $jsonOutString);
		fclose($jsonOut);
		header("Refresh:0");
	}
?>
			</main>

			</br>
			
</body>

</html>