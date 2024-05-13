const express = require('express');
const app = express();

var path = require('path');

const {VM} = require("vm2");


app.set('static', path.join(__dirname, 'static'));
var staticPath = path.join(__dirname, 'static');
app.use(express.static(staticPath));

app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'ejs');

const bodyParser = require("body-parser");

app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());




app.get('/', async function (req, res) {

  res.render("index", {calculation: null})

});


app.get('/info', async function (req, res) {

  res.render("info", {})

});


app.post('/postData', async function (req, res) {
  
  const userInput = req.body.calc1

  const vm = new VM();

  console.log(userInput)

  try{

      const result = await vm.run( userInput, 'vm.js' );


      console.log("vm run ",result);

      const data = { 
        calculation: result
      }

      res.render("index",data)

  }

  catch(error){

    const data = { 
      message: error
    }
      
    res.render("error",data)
  }


});



app.listen(5000);

module.exports = app;
