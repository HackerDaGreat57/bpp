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

class start_popup extends React.Component { //Create the start popup.
  render() {
    return React.createElement("div", {
      style: {
        backgroundColor: 'white',
        width: '50%',
        height: '50%',
        borderRadius: '10px',
        position: 'absolute',
        top: '25%',
        left: '25%',
        boxShadow: '0px 0px 10px black'
      }
    }, null, React.createElement("div", {
      style: {
        backgroundColor: '#454545',
        width: '100%',
        height: '10%',
        borderTopLeftRadius: '10px',
        borderTopRightRadius: '10px',
        color: 'white',
        fontFamily: 'bpp_Tahoma',
        fontSize: '1.5em',
        fontWeight: 'bold',
        textAlign: 'center',
        paddingTop: '10px'
      }
    }, null, "Welcome to Blender++ Live!"));
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