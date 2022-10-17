//main.js: Blender++ Live main source code

//Create the screen, basically
const reactElement = React.createElement;

class app_title extends React.Component {
  render() {
    return React.createElement("span", {
      style: {
        fontFamily: 'bpp_Tahoma',
        fontSize: '2em',
        fontWeight: 'bold',
        color: 'white'
      }
    }, null, "Blender++ Live");
  }
}

document.body.style.backgroundColor = '#454545';
document.body.style.width = '100%';
document.body.style.height = '100%';

const domContainer = document.querySelector('#render_area');
const root = ReactDOM.createRoot(domContainer);
root.render(reactElement(app_title));