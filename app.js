const express = require("express");
const bodyParser = require("body-parser");
// const request = require("request");
const https = require("https");

const app = express();


app.use(express.static("public"));
app.use(bodyParser.urlencoded({extended: true}));


// Intro page.
app.get("/", function(req, res)
{
    res.sendFile(__dirname+"/signup.html");
});


// We will have to create a json file because the mailchimp 
// will accept only the json file and nothing else so we need to 
// create a java script object.

app.post("/", function(req, res)
{
    const firstName = req.body.fName;
    const lastName = req.body.lName;
    const email = req.body.email;

        // mailchip will accept using the function members so
        // we need to use that and it is an array.
    const data ={
        members : [
            {
                email_address : email,
                status: "subscribed",
                merge_field : {
                    FNAME: firstName,
                    LNAME: lastName
                }
            }
        ]
    };

    const jsonData = JSON.stringify(data);

    const url = "https://us20.api.mailchimp.com/3.0/lists/fcd0d52b7c"

    // Now we will create some options which is going to be some js objects.
    const options = {
        method: "POST",
        // We need to get something for authentication, we will use auth for authentication
        auth: "shanu:6e7a621c8a3d2968ce748280c12f8d97-us20"
    }

    const request = https.request(url, options, function(response)
    {
        if(response.statusCode === 200)
        {
            res.sendFile(__dirname+"/success.html");
        }
        else{
            res.sendFile(__dirname+"failure.html");
        }



        response.on("data", function(data)
        {
            console.log(JSON.parse(data));
        })
    })

    request.write(jsonData);
    request.end();



    console.log(firstName, lastName, email );

});

app.post("/failure", function(req, res)
{
    res.redirect("/");
});

app.post("/success", function(req, res)
{
    res.redirect("https://www.youtube.com/channel/UCnT6Z9ay-snq1c0lZkEtYjg");
});




app.listen(process.env.PORT || 3000, function()
{
    console.log("Server is running on port 3000");
});


// API key for mailchip
// 6e7a621c8a3d2968ce748280c12f8d97-us20


// Audiance id:
// fcd0d52b7c