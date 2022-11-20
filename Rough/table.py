file = open("table.html","w")

users = [
    {
        '_id': '123',
        'totalUser': 3,
        'Role 2': 2,
        'Role 1': 1
    },
    {
        '_id': '123',
        'totalUser': 3,
        'Role 2': 2,
        'Role 1': 1
    },
    {
        '_id': '123',
        'totalUser': 3,
        'Role 2': 2,
        'Role 1': 1
    },
]

headings = {
    "ID",
    "TotalUser",
    "Role 2",
    "Role 3"
}


# Adding Headers
columns = ""
for header in headings:
    columns += "<td> {} <td>".format(header)
headers = "<tr> {} <tr>".format(columns)


# Addint Data
body = ""
for row in users:
    body += "<tr> <td> {} <td> <td> {} <td> <td> {} <td> <td> {} <td> <tr>".format(
        row['_id'], row['totalUser'], row['Role 2'], row['Role 1']
    )


# Html Content
html_doc = """
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0/dist/css/bootstrap.min.css" integrity="sha384-gH2yIJqKdNHPEq0n4Mqa/HGKIhSkIHeL5AyhkYV8i59U5AR6csBvApHHNl/vI1Bx" crossorigin="anonymous">
    <title>Data Table</title>
</head>
<body>
    <div class="container mt-5">
        <table class="table table-dark" > {} {} <table/>
    </div>
</body>
</html>
""".format(headers, body)


# Writing to HTML file
file.write(html_doc)
  
# Closing File
file.close()