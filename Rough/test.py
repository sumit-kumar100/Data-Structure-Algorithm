from html2image import Html2Image
hti = Html2Image()

font = 100

html = """
<div>
    <p>TEST</p>
</div>
"""
css = """
    *{ 
        margin:0; 
        padding:0;
    } 
    body{
        background: red;
    } 
    div {
        background: white; 
        height:100vh; 
        width: 100vw;
        display: flex; 
        justify-content: center;  
        align-items: center;

    }
    p{
        font-size:100%;
        font-family: monospace;
    }

"""

hti.screenshot(
    html_str=html, css_str=css,
    save_as='test.png',
    size=(font, font)
)
