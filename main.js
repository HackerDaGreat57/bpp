//main.js: Blender++ Live main source code

const reactElement = React.createElement; //Create the screen, basically.

class app_title extends React.Component { //Create the title element.
  render() {
    return React.createElement("span", {
      style: {
        fontFamily: 'bpp_Tahoma',
        fontSize: '3em',
        fontWeight: 'bold',
        color: 'white'
      }
    }, null, "Blender++ Live");
  }
};

class start_popup extends React.Component { //Create the start pop-up.
  render() {
    return React.createElement("div", {
      style: {
        position: 'absolute',
        top: '50%',
        left: '50%',
        transform: 'translate(-50%, -50%)',
        width: '50%',
        height: '50%',
        backgroundColor: 'white',
        borderRadius: '10px',
        boxShadow: '0px 0px 10px #000000',
        animation: 'fly-in 0.5s ease-in-out',
        animationFillMode: 'forwards'
      }
    }, null, "Welcome to Blender++ Live!");
  }
};

//Set the background style.
document.body.style.backgroundColor = '#454545';
document.body.style.width = '100%';
document.body.style.height = '100%';

//Finish up and render stuff
const domContainer = document.querySelector('#render_area');
const root = ReactDOM.createRoot(domContainer);
root.render(reactElement(app_title));
root.render(reactElement(start_popup));