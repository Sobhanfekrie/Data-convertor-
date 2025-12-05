// api.php
$output_file = "output/output.txt";

if(file_exists($output_file)) {
    echo "<h2>Output File Content:</h2>";
    echo "<pre>" . htmlspecialchars(file_get_contents($output_file)) . "</pre>";
} else {
    echo "Output file not found!";
}
?>
