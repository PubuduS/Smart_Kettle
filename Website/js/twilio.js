const accountSid = '';
const authToken =  '';

const client = require('twilio')(accountSid, authToken0);

client.messages.create({
  to: '',
  from: '',
  body: ''
})
.then((message) => console.log(message.sid));
