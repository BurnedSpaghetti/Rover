/**
 * Opening and getting info about SD Card
 */

SdFile root;

void CardSetup(){
  Serial.print("\nInitializing SD card... ");

  // Checking if card is present & initializing it
  if (!card.init(SPI_HALF_SPEED, chipSelect)) {
    Serial.println("Failed");
    Serial.println(" - Make sure card is connected properly");
    Serial.println(" - It is FAT16/FAT32 partition");
    while (1);
  } else {
    // Initialization
    if (!SD.begin(chipSelect)) { // Might need to change pin # depending on the board
      Serial.println("initialization failed!");
      while(1);
    }
  }

  // Opening 'volume' on card
  if (!volume.init(card)) {
    Serial.println("Could not find FAT16/FAT32 partition.");
    Serial.println("Make sure you've formatted the card.");
    while (1);
  }

  // Listing all files found on the card
  // this is for testing purposes mostly
  Serial.println("Files on card: ");
  root.openRoot(volume);
  root.ls(LS_R | LS_DATE);
  Serial.println("-------------------------------\n");

  Serial.println(checkCanOpenFile(readFileName));
}

bool checkCanOpenFile(String fileName){
  Serial.println("Checking " + fileName);
  if(SD.exists(fileName)){
    Serial.println("File " + fileName + " exists.");
  }
  else{
    Serial.println("File " + fileName + " does not exist");
    return false;
  }

  // Making sure we can read rom the file
  readFile = SD.open(fileName, FILE_READ);
  if(readFile){
    Serial.print("Able to open " + fileName + " for reading - ");
    //printFile(readFile); // for debugging
    
    // MUST close the file
    readFile.close();
    Serial.println("YES");
    return true; 
  }
  else{ // were not able to open file
    Serial.println("NO");
    return false;
  }
}

/**
 * Printing content of the file
 * used for debugging mostly
 */
void printFile(File file){
      while(file.available()){
        Serial.write(file.read());
    }
}
