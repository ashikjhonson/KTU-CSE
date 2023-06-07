const pagesArray = [1,2,3,4,5,2,6];
const frames = 4;
let index = 0, miss = 0, hit = 0;
const framesArray = [];
let pfr = document.getElementById('pfr');

fifo = ()=>{
    
    let pPages = document.createElement('p');
    pPages.textContent = "Pages = {"+pagesArray+"}";
    pfr.appendChild(pPages);

    pagesArray.forEach(number=>{
        let pFrame = document.createElement('p');
        pFrame.textContent = "Page: "+number;
        if(framesArray.includes(number)){
            hit += 1;
            pFrame.textContent += " ----- Hit -";
        }
        else{
            miss += 1;
            pFrame.textContent += " ---- Miss ";
            if(framesArray.length<frames){
                framesArray.push(number);
            }
            else{
                framesArray[index] = number;
                index = index%frames + 1; 
            }
        }
        pFrame.textContent += "---- ["+framesArray+"]";
        console.log(framesArray);
        document.body.appendChild(pFrame);
    })
}

fifo();
