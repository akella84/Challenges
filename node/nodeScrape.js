
//References
//https://www.npmjs.org/package/cheerio#readme
//http://maxogden.com/scraping-with-node.html

/*
* table schema
CREATE TABLE `test`.`scraper` (
  `id` INT NOT NULL,
  `url` VARCHAR(90) NULL,
  `key` INT NULL,
  `keyCount` INT NULL,
  `lastScraped` VARCHAR(45) NULL,
  `lastModified` VARCHAR(45) NULL,
  PRIMARY KEY (`id`)
  AUTO_INCREMENT(`id`));
*/  

var db = require('mysql'); //import mysql module 
var cheerio = require('cheerio'); //import cheerio html parser
var request = require('request'); //import the request module required by cheerio


//establish the db connection
var connection = db.createConnection(
   {
  	host :'localhost',
  	user : 'root',
  	password: '1q2w3e4r',
  }
);

//inititate the db connection
connection.connect();

//cleanup the database before starting (if set)
var truncateDB = 1; // 0 to make the scrapped result persistent across multiple runs

//truncate the table to start fresh crawl
var truncateQuery = 'TRUNCATE TABLE test.scraper';
if(truncateDB)
  resultQuery(truncateQuery);

// trigger the scrapping process
var domain = 'http://www.cnn.com'
console.log("Starting to scrape " + domain + " ... ")
request(domain, processPage);

//----------------------------------------------

// this function takes in a query string to insert along with related set of values
function valueQuery(s, val) {
  var query = connection.query(s, val, function(err, result) {      
      if(err)
         console.log(err);
  });
  
  //console.log(query.sql);
}

// this function is used to retrieve info from db
function resultQuery(s) {
  connection.query(s, function(err, rows) {
    if (err) throw err;
    value = rows.length;
    //for (i=0; i< value; i++)
    //  console.log(rows[i]);
  });
}

// this function is used to retrieve info from db by passing values on condition
function conditionalQuery(s, val, callback) { 
  var retValue
  connection.query(s, val, function(err, rows) {
   if (err) {
       console.error(err)
    }
    else{
      retValue = rows.length;
      //for (i=0; i< value; i++)
      //  console.log(rows[i]);  
    }

    callback(retValue);
  });


}

// this function makes use of the cheerio module to parse html file and 
// searches for the key word
function processPage(err, resp, body) {
  if (err) 
    return console.error(err)
  
  var parsedHTML = cheerio.load(body)

  var matchedURLs = []
  parsedHTML('a').map(function(index, link) {
  var href = cheerio(link).attr('href')
    
  if(href != undefined){
        if(href.charAt(0) == '/'){
           matchedURLs.push(domain + href) 
         }  
         else if (href.search("http://") > 0){
           matchedURLs.push(href) 
         }         
    }
  })
  
  //recur through the list
  for (i=0; i< matchedURLs.length; i++){
        
    var queryString = 'SELECT * FROM test.scraper where `url` = ?';
    
    // if this url doesn`t exist in the db
    conditionalQuery(queryString, matchedURLs[i], function(cond){
    if(cond == 0){
      //console.log(cond);
      var post = {url: matchedURLs[i], lastScraped: new Date().toTimeString()};
      var insertQuery = 'INSERT INTO test.scraper SET ?';
      if (matchedURLs[i] != null) 
         valueQuery(insertQuery, post);   
    }
    else{
      console.log("skipping already scraped pages ... ")
    }

    });
    
        
     //console.log(matchedURLs[i]);
     request(matchedURLs[i], processPage)
  }  
}


//started to write this function that searches for a match 
// in the content but couldn`t get to that point
function findKey(err, resp, body) {
  if (err) return console.error(err)
  var parsedBody = cheerio.load(body)
  
  var matchedText = [];
  var result = parsedBody('body').find('canada');
  parsedBody('canada').each(function(){
      matchedText.push(parsedBody(this).text())
  });    
  
 
  console.log(result.length);
  for (i=0; i< matchedURLs.length; i++)
    console.log(matchedURLs[i]);
}

