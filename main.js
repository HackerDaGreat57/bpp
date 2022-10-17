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
}

class start_popup extends React.Component { //Create the pop-up box.
  render() {
    return React.createElement("div", {
      style: {
        backgroundColor: '#454545',
        width: '100%',
        height: '100%',
        position: 'absolute',
        top: '0',
        left: '0',
        zIndex: '1'
      }
    }, null, "Hello World!");
  }
}

//Set the background style.
document.body.style.backgroundColor = '#454545';
document.body.style.width = '100%';
document.body.style.height = '100%';

//Finish up and render stuff
const domContainer = document.querySelector('#render_area');
const root = ReactDOM.createRoot(domContainer);
root.render(reactElement(app_title));
root.render(reactElement(start_popup));