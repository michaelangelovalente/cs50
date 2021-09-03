let str = "This is your new pet cat!"

let cats = ["../../images/cats/cat1.jpg","../../images/cats/cat2.jpg", "../../images/cats/cat3.jpg", "../../images/cats/cat4.jpg", "../../images/cats/cat5.jpg", "../../images/cats/cat6.jpg" ];

function randomInt(max){
    return Math.floor(Math.random() * max);
}
function changepic(){
    //document.querySelector('#picture').src=dogs[randomInt(dogs.length)];
    document.querySelector('#picture').src= cats[randomInt(cats.length)];
    document.querySelector('#pet_txt').innerHTML = str;
}


document.addEventListener('DOMContentLoaded', function(){
    document.querySelector('.btn').addEventListener('click',function(){
        changepic();
    });
});

